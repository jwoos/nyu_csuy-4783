const DIMENSION = {
	width: 1900,
	height: 950,
	margin: {
		left: 50,
		right: 250,
		top: 100,
		bottom: 75
	}
};

DIMENSION.trueWidth = DIMENSION.width - (DIMENSION.margin.left + DIMENSION.margin.right);
DIMENSION.trueHeight = DIMENSION.height - (DIMENSION.margin.top + DIMENSION.margin.bottom);

const monthQuarterMap = {
	1: 1,
	4: 2,
	7: 3,
	10: 4
};

const CONTAINER = '#chart';

const loadData = () => {
	return new Promise((resolve, reject) => {
		d3.queue()
			.defer(d3.json, 'Las Vegas Business.json')
			.await((err, ...data) => {
				if (err) {
					reject(err);
				} else {
					resolve(data);
				}
			});
	});
};

const init = (container) => {
	d3.select(CONTAINER)
		.attr('width', DIMENSION.width)
		.attr('height', DIMENSION.height);
};

const transformData = (data) => {
	const transformed = {};

	const categories = {};
	transformed.categories = categories;

	const years = new Set();
	transformed.years = years;

	const dates = new Set();
	transformed.dates = dates;

	const negative = new Set();
	transformed.negative = negative;

	const greatChange = new Set();
	transformed.greatChange = greatChange;

	const stats = {
		count: 0,
		sum: 0,
		changeSum: 0,
		changeCount: 0
	};
	transformed.stats = stats;

	for (let restaurant of data) {
		const category = restaurant.category;

		const threshold = 3;
		let belowThreshold = 0;
		const changeTreshold = -2;
		let aboveChangeThreshold = 0;

		for (let q of restaurant.quarters) {
			stats.count++;
			stats.sum += q.rating;

			if (q.rating <= threshold) {
				belowThreshold += 1;
			}

			const date = new Date(`${q.quarter} EST`);

			years.add(date.getFullYear());
			dates.add(q.quarter);
			q.quarter = date;
		}

		if (belowThreshold >= (0.75 * restaurant.quarters.length)) {
			negative.add(restaurant);
		}

		if (!categories[category]) {
			categories[category] = [restaurant];
		} else {
			categories[category].push(restaurant);
		}

		restaurant.quarters.sort((a, b) => {
			const aQuarter = a.quarter;
			const bQuarter = b.quarter;

			if (aQuarter < bQuarter) {
				return -1;
			} else if (aQuarter > bQuarter) {
				return 1;
			} else {
				return 0;
			}
		});

		let prev = null;
		for (let q of restaurant.quarters) {
			if (prev) {
				const diff = q.rating - prev;

				if (diff <= changeTreshold) {
					aboveChangeThreshold += 1;
					greatChange.add(restaurant);
				}

				stats.changeCount++;
				stats.changeSum += diff;

				prev = q.rating;
			} else {
				prev = q.rating;
			}

		}
	}

	stats.average = stats.sum / stats.count;
	stats.changeAverage = stats.changeSum / stats.changeCount;

	transformed.years = Array.from(transformed.years).sort();
	transformed.dates = Array.from(transformed.dates).sort().map(d => new Date(`${d} EST`));

	return transformed;
};

loadData().then(([data]) => {
	init(CONTAINER);

	const transformed = transformData(data);

	window.data = data;
	window.transformed = transformed;

	const container = d3.select(CONTAINER);

	container.append('text')
		.text('Change in Restaurant Rating Over Time')
		.attr('dx', DIMENSION.trueWidth / 2)
		.attr('dy', 30)
		.attr('text-anchor', 'middle')
		.attr('fill', 'black')
		.attr('font-size', 24);

	const tooltip = d3.select('body')
		.append('div')
		.attr('class', 'tooltip')
		.style('visibility', 'hidden');

	const colorScale = d3.scaleOrdinal()
		.range(d3.schemeCategory20)
		.domain(Object.keys(transformed.categories));

	const xScale = d3.scaleTime()
		.range([0, DIMENSION.trueWidth])
		.domain([transformed.dates[0], transformed.dates[transformed.dates.length - 1]]);
	const yScale = d3.scaleLinear()
		.range([DIMENSION.trueHeight, 0])
		.domain([1, 5]);

	const averageBox = container.append('rect')
		.attr('transform', `translate(${DIMENSION.margin.left}, ${DIMENSION.margin.top + (DIMENSION.trueHeight / 2)})`)
		.attr('width', DIMENSION.trueWidth)
		.attr('height', DIMENSION.trueHeight / 2)
		.attr('fill', '#ffeaea');

	const linesContainer = {};
	const filtersContainer = {};
	const state = {};
	const legendState = {};

	let i = 0;
	for (let k of Object.keys(transformed.categories)) {
		i++;
		state[k] = true;
		legendState[k] = false;

		filtersContainer[k] = d3.select('body')
			.append('div')
			.attr('id', `filter-${k.split(' ')[0]}`)
			.attr('class', 'filter')
			.style('top', 305 + (30 * i))
			.style('left', DIMENSION.trueWidth + 100)
			.style('height', 150)
			.style('visibility', 'hidden')
			.append('form');

		filtersContainer[k].append('button')
			.attr('value', k)
			.text('ALL ON')
			.on('click', (_, __, [target]) => {
				d3.event.preventDefault();

				const val = target.value.split(' ')[0];
				d3.selectAll(`.category-${val}.line`)
					.style('visibility', '');
				d3.selectAll(`.category-${val}.circle`)
					.style('visibility', '');
				d3.selectAll(`.toggle-${val}`)
					.property('checked', true);

				for (let node of d3.selectAll(`.toggle-${val}`).nodes()) {
					state[node.value] = true;
				}
			});

		filtersContainer[k].append('button')
			.attr('value', k)
			.text('ALL OFF')
			.on('click', (_, __, [target]) => {
				d3.event.preventDefault();

				const val = target.value.split(' ')[0];

				d3.selectAll(`.category-${val}.line`)
					.style('visibility', 'hidden');
				d3.selectAll(`.category-${val}.circle`)
					.style('visibility', 'hidden');
				d3.selectAll(`.toggle-${val}`)
					.property('checked', false);

				for (let node of d3.selectAll(`.toggle-${val}`).nodes()) {
					state[node.value] = false;
				}
			});

		linesContainer[k] = container.append('g')
			.attr('transform', `translate(${DIMENSION.margin.left}, ${DIMENSION.margin.top})`)
			.attr('class', `category-${k.split(' ')}`);
	}

	for (let i = 0; i < data.length; i++) {
		const restaurant = data[i];
		state[restaurant.business_id] = true;

		const line = d3.line()
			.x(d => xScale(d.quarter))
			.y(d => yScale(d.rating));

		const div = filtersContainer[restaurant.category].append('div');

		div.append('input')
			.attr('type', 'checkbox')
			.attr('id', `toggle-${restaurant.business_id}`)
			.attr('class', `toggle-${restaurant.category} toggle`)
			.attr('value', restaurant.business_id)
			.attr('checked', true)
			.on('click', (_, __, [target]) => {
				const val = target.value;
				state[val] = state[val] ^ true;
				d3.select(`#restaurant-${val}`)
					.style('visibility', state[val] ? '' : 'hidden');
				d3.selectAll(`.restaurant-${val}`)
					.style('visibility', state[val] ? '' : 'hidden');
			});

		div.append('label')
			.attr('for', `toggle-${restaurant.business_id}`)
			.text(restaurant.business_name);

		linesContainer[restaurant.category].append('path')
			.datum(restaurant.quarters)
			.attr('id', `restaurant-${restaurant.business_id}`)
			.attr('class', `category-${restaurant.category} line`)
			.attr('fill', 'none')
			.attr('stroke', colorScale(restaurant.category))
			.attr('d', line)
			.on('mouseover', (d, i, self) => {
				self[i].setAttribute('stroke-width', 10);

				const [tooltipX, tooltipY] = d3.mouse(self[i]);
				tooltip.style('visibility', 'visible');

				tooltip.html(`Restaurant: ${restaurant.business_name}`)
					.style('left', `${tooltipX}px`)
					.style('top',  `${tooltipY + 60}px`);
			})
			.on('mousemove', (d, i, self)=> {
				const [tooltipX, tooltipY] = d3.mouse(self[i]);

				tooltip.html(`Restaurant: ${restaurant.business_name}`)
					.style('left', `${tooltipX}px`)
					.style('top',  `${tooltipY + 60}px`);
			})
			.on('mouseout', (d, i, self) => {
				self[i].setAttribute('stroke-width', 1);
				tooltip.style('visibility', 'hidden');
			});

		linesContainer[restaurant.category].selectAll(`.${restaurant.category[0] + i}`)
			.data(restaurant.quarters)
			.enter()
			.append('circle')
			.attr('class', `restaurant-${restaurant.business_id} category-${restaurant.category} circle`)
			.attr('r', 3)
			.attr('cy', d => yScale(d.rating))
			.attr('cx', d => xScale(d.quarter))
			.on('mouseover', (d, i, self) => {
				self[i].setAttribute('r', 5);

				const [tooltipX, tooltipY] = d3.mouse(self[i]);
				tooltip.style('visibility', 'visible');

				tooltip.html(`Restaurant: ${restaurant.business_name}<br>Time: ${d.quarter.getFullYear()} Q${monthQuarterMap[d.quarter.getMonth() + 1]}<br>Rating: ${d.rating}<br>Total Reviews: ${d.count}`)
					.style('left', `${tooltipX}px`)
					.style('top',  `${tooltipY}px`);
			})
			.on('mouseout', (d, i, self) => {
				self[i].setAttribute('r', 3);
				tooltip.style('visibility', 'hidden');
			});
	}

	const legend = container.append('g')
		.attr('transform', `translate(${DIMENSION.trueWidth + 75 }, 300)`)
		.attr('id', 'legend')
		.append('g')
		.selectAll('g')
		.data(Object.keys(linesContainer))
		.enter()
		.append('g')
		.attr('transform', (d, i) => `translate(0, ${30 * i})`)

	legend.append('rect')
		.attr('width', 20)
		.attr('height', 20)
		.attr('id', d => `color-${d.split(' ')[0]}`)
		.attr('class', 'legend-color')
		.attr('stroke', 'black')
		.attr('fill', d => colorScale(d))
		.on('click', (d, i, self) => {
			state[d] = state[d] ^ true;
			self[i].setAttribute('fill', state[d] ? colorScale(d) : 'white');
			linesContainer[d].style('visibility', state[d] ? 'visible' : 'hidden');
		});

	legend.append('text')
		.attr('x', 10 + 15)
		.attr('y', 10 + 5)
		.style('cursor', 'pointer')
		.on('click', (d, _, __) => {
			legendState[d] = legendState[d] ^ true;
			d3.select(`#filter-${d.split(' ')[0]}`)
				.style('visibility', legendState[d] ? 'visible' : 'hidden')
		})
		.text(d => `${d} (${transformed.categories[d].length})`);

	const xAxis = d3.axisLeft(yScale)
		.ticks(10);
	const yAxis = d3.axisBottom(xScale)
		.ticks(50)
		.tickFormat(v => `${v.getFullYear()} Q${monthQuarterMap[v.getMonth() + 1]}`);

	const axes = container.append('g')
		.attr('transform', `translate(${DIMENSION.margin.left}, ${DIMENSION.margin.top})`);

	// x-axis
	axes.append('g')
		.call(xAxis)
		.append('text')
		.text('Average Rating')
		.attr('dx', -30)
		.attr('dy', DIMENSION.trueHeight / 2)
		.attr('text-anchor', 'middle')
		.attr('fill', 'black')
		.attr('font-size', 14)
		.attr('transform', `rotate(270, -30, ${DIMENSION.trueHeight / 2})`);

	// y-axis
	const axesY = axes.append('g')
		.attr('transform', `translate(0, ${DIMENSION.trueHeight})`);

	axesY.call(yAxis)
		.selectAll('text')
		.attr('transform', 'rotate(-90, 0, 13)')
		.attr('text-anchor', 'end');

	axesY.append('text')
		.text('Quarter')
		.attr('dx', DIMENSION.trueWidth / 2)
		.attr('dy', 65)
		.attr('text-anchor', 'middle')
		.attr('fill', 'black')
		.attr('font-size', 14);

	const analysisTitles = {};
	const selectContainer = d3.select('body')
		.append('select')
		.attr('class', 'version-choice')
		.on('change', (_, __, [target]) => {
			switch (target.value) {
				case 'DEFAULT':
					for (let node of d3.selectAll('.toggle').nodes()) {
						state[node.value] = true;
						d3.select(`#restaurant-${node.value}`)
							.style('visibility', '');
						d3.selectAll(`.restaurant-${node.value}`)
							.style('visibility', '');
					}

					for (let k of Object.keys(analysisTitles)) {
						analysisTitles[k].remove();
						delete analysisTitles[k];
					}

					for (let category of Object.keys(transformed.categories)) {
						state[category] = true;
						d3.select(`#color-${category.split(' ')[0]}`)
							.attr('fill', colorScale(category));
						linesContainer[category]
							.style('visibility', 'visible');
					}

					break;

				case 'Analysis 1':
					for (let k of Object.keys(analysisTitles)) {
						analysisTitles[k].remove();
						delete analysisTitles[k];
					}

					d3.selectAll('.line')
						.style('visibility', 'hidden');
					d3.selectAll('.circle')
						.style('visibility', 'hidden');

					for (let restaurant of transformed.negative) {
						d3.select(`#restaurant-${restaurant.business_id}`)
							.style('visibility', 'visible');
						d3.selectAll(`.restaurant-${restaurant.business_id}`)
							.style('visibility', 'visible');
						analysisTitles[restaurant.business_id] = container
							.append('text')
							.attr('dx', xScale(restaurant.quarters[0].quarter) + 50)
							.attr('dy', yScale(restaurant.quarters[0].rating) + 90)
							.attr('font-size', 11)
							.text(restaurant.business_name);
					}

					break;

				case 'Analysis 2':
					for (let k of Object.keys(analysisTitles)) {
						analysisTitles[k].remove();
						delete analysisTitles[k];
					}

					d3.selectAll('.line')
						.style('visibility', 'hidden');
					d3.selectAll('.circle')
						.style('visibility', 'hidden');

					for (let restaurant of transformed.greatChange) {
						d3.select(`#restaurant-${restaurant.business_id}`)
							.style('visibility', 'visible');
						d3.selectAll(`.restaurant-${restaurant.business_id}`)
							.style('visibility', 'visible');
						analysisTitles[restaurant.business_id] = container
							.append('text')
							.attr('dx', xScale(restaurant.quarters[0].quarter) + 50)
							.attr('dy', yScale(restaurant.quarters[0].rating) + 90)
							.attr('text-anchor', 'start')
							.attr('font-size', 11)
							.text(restaurant.business_name);
					}
					break;
			}
		});

	selectContainer.append('option')
		.attr('value', 'DEFAULT')
		.attr('selected', true)
		.text('DEFAULT');
	selectContainer.append('option')
		.attr('value', 'Analysis 1')
		.property('selected', false)
		.text('Analysis 1');
	selectContainer.append('option')
		.attr('value', 'Analysis 2')
		.property('selected', false)
		.text('Analysis 2');
});
