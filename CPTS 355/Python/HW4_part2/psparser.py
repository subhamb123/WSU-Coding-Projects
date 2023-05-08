"""Parts of the lexer and parser code was adopted from https://composingprograms.com/. 
The code has been changed according to Postscript syntax. 
https://creativecommons.org/licenses/by-sa/3.0/
"""
import string
from buffer import Buffer
from psexpressions import Literal, PSString,  PSName, PSCodeArray
from colors import *

# Constants
SYMBOL_STARTS = set(string.ascii_lowercase + string.ascii_uppercase + '_' + '/'+',')
SYMBOL_INNERS = SYMBOL_STARTS | set(string.digits + ',' + '-') 
NUMERAL = set(string.digits + '-.')
WHITESPACE = set(' \t\n\r')
DELIMITERS = set('(){}[]')
BOOLEANS =  {'true':True, 'false':False}
  
#---------------------------------------------------
#   Lexer #
#---------------------------------------------------

"""Splits the string s into tokens and returns a list of them.
>>> tokenize('/addsq { /sq {dup mul} def sq exch sq add exch sq add } def  2 3 4 addsq')  """
def tokenize(s):
    src = Buffer(s)
    tokens = []
    while True:
        token = next_token(src)
        if token is None:
            #print(RED+"tokens"+CEND,tokens)
            return tokens
        tokens.append(token)

""" Takes allowed characters only. Filters out everything else.  """
def take(src, allowed_characters):
    result = ''
    while src.current() in allowed_characters:
        result += src.pop_first()
    return result

"""Returns the next token from the given Buffer object. """
def next_token(src):
    take(src, WHITESPACE)  # skip whitespace
    c = src.current()
    if c is None:
        return None
    elif c in NUMERAL:
        literal = take(src, NUMERAL)
        try:
            return int(literal)
        except ValueError:
            try:
                return float(literal)
            except ValueError:
                raise SyntaxError("'{}' is not a numeral".format(literal))
    elif c in SYMBOL_STARTS:
        sym = take(src, SYMBOL_INNERS)
        if sym in BOOLEANS.keys():
            return BOOLEANS[sym] # FIX this for next year
        else: 
            return sym
    elif c in DELIMITERS:
        src.pop_first()
        return c
    else:
        raise SyntaxError("'{}' is not a token".format(c))

#---------------------------------------------------
#   Parser #
#---------------------------------------------------

# Helper functions for the parser.

""" Checks if the given token is a literal - primitive constant value. """
def is_literal(s):
    return isinstance(s, int) or isinstance(s, float) or isinstance(s,bool) 

""" Checks if the given token is a variable or function name. 
    The name can either be: 
    - a name constant (where the first character is /) or 
    - a variable, function, or built-in operator  """
def is_name(s):
    return isinstance(s, str) and s not in DELIMITERS

""" Returns the constant string enclosed within matching () paranthesis. """
def read_str_constant(src):
    s = []
    while src.current() != ')':
        if src.current() is None:
            raise SyntaxError("String doesn't have a matching `)`!")
        s.append(str(src.pop_first()))
    "Pop the `)`."
    src.pop_first()
    "Will insert ` ` between tokens."    
    return '(' + ' '.join(s) + ')'

""" Returns the constant code array enclosed within matching  {} paranthesis.  """
def read_block_expr(src):
    s = []
    while src.current() != '}':
        if src.current() is None:
            raise SyntaxError("Doesn't have a matching '{}'!".format('}'))
        s.append(read_expr(src))
    "Pop the `}`."
    src.pop_first()
    return s    

""" Converts the next token in the given Buffer to an expression. """
def read_expr(src):
    token = src.pop_first()
    if token is None:
        raise SyntaxError('Incomplete expression')
    # TO-DO  - complete the following; include each condition as an `elif` case.
    #   if the token is a literal return a `Literal` object having `value` token.
    #   if the token is a string delimiter (i.e., '('), get all tokens until the matching ')' delimiter and combine them as a Python string; 
    #       create a PSString object having this string value. 
    #   if the token is a name, create a PSName object having `var_name` token. 
    #   if the token is a code-array delimiter (i.e., '{'), get all tokens until the matching '}' delimiter and combine them as a Python list; 
    #       create a PSCodeArray object having this list value.
    elif is_literal(token):
        return Literal(token)
    elif token == '(':
        return PSString(read_str_constant(src))
    elif is_name(token):
        return PSName(token)
    elif token == '{':
        return PSCodeArray(read_block_expr(src))
    else:
        raise SyntaxError("'{}' is not the start of an expression".format(token))

"""Parse an expression from a string. If the string does not contain an
   expression, None is returned. If the string cannot be parsed, a SyntaxError
   is raised.
"""
def read(s):
    #reading one token at a time
    src = Buffer(tokenize(s))  
    out = []
    while src.current() is not None:
        out.append(read_expr(src))
    #print(OKGREEN+'out'+CEND,out)
    return out