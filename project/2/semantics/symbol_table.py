from enum import Enum
import inspect
import json

from parser.ast import Node


class CustomEncoder(json.JSONEncoder):
    def default(self, o):
        if inspect.isclass(o):
            return o.__name__
        elif isinstance(o, Symbol) or isinstance(o, Node):
            return o.__str__()
        else:
            return super().default(o)


class SymbolScope(Enum):
    LOCAL = 1
    GLOBAL = 2
    ANY = 3


class SymbolType(Enum):
    FUNCTION = 1
    VARIABLE = 2


class Symbol:
    def __init__(self, scope, kind, attrs=None):
        self.scope = scope
        self.kind = kind

        self.attrs = attrs
        if not attrs:
            self.attrs = {
                'init': False,
                'type': None,
                'arg': None,
                'arg_type': None,
                'name': None,
                'line': None,
                'value': None,
                'inferred_type': None,
                'inferred_arg_type': None,
                'placeholder': False
            }

    def __str__(self):
        return f'<Symbol {self.scope} {self.kind} {json.dumps(self.attrs, cls=CustomEncoder)}>'

    def __repr__(self):
        return self.__str__()


class SymbolTable:
    def __init__(self, scope):
        self.scope = scope
        self.table = {}

    def __str__(self):
        return json.dumps(self.table, indent=True, cls=CustomEncoder)

    def __repr__(self):
        return self.__str__()

    def get(self, key):
        return self.table.get(key, None)

    def set(self, key, symbol):
        if symbol.kind == SymbolType.FUNCTION:
            table_symbol = self.table.get(key)
            if table_symbol and table_symbol.attrs['init']:
                return f'function {key} already defined'

            if table_symbol:
                # make sure all properties are good
                for prop in ('type', 'arg_type'):
                    if symbol.attrs[prop] != table_symbol.attrs[prop]:
                        return f'Type error mistmatch - declared is {table_symbol.attrs[prop]} and defined is {symbol.attrs[prop]}'

                table_symbol.attrs = symbol.attrs
        else:
            if self.table.get(key):
                return f'{key} already defined'

        self.table[key] = symbol

    def clear(self):
        self.table = {}


def info(symbol, usage=0):
    msg = ''
    if symbol.kind == SymbolType.FUNCTION:
        if symbol.attrs['init']:
            msg = f'Function {symbol.attrs["type"]} {symbol.attrs["name"]} ({symbol.attrs["arg_type"]} {symbol.attrs["arg"]}) defined on line {symbol.attrs["line"]}'
        else:
            msg = f'Function {symbol.attrs["type"]} {symbol.attrs["name"]} ({symbol.attrs["arg_type"]}) declared on line {symbol.attrs["line"]}'
    else:
        if symbol.scope == SymbolScope.GLOBAL:
            msg = f'Global {symbol.attrs["type"]} variable {symbol.attrs["name"]} declared on line {symbol.attrs["line"]}'
        else:
            msg = f'Local {symbol.attrs["type"]} variable {symbol.attrs["name"]} declared on line {symbol.attrs["line"]}'

    if usage:
        msg += f' used on line {usage}'

    print(msg)
