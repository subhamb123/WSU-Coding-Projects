#Subham Behera

from colors import *
from psexpressions import StringValue, DictionaryValue, CodeArrayValue

class PSOperators:
    def __init__(self):
        #stack variables
        self.opstack = []  #assuming top of the stack is the end of the list
        self.dictstack = []  #assuming top of the stack is the end of the list
        # The environment that the REPL evaluates expressions in.
        # Uncomment this dictionary in part2
        self.builtin_operators = {
            "add":self.add,
            "sub":self.sub,
            "mul":self.mul,
            "mod":self.mod,
            "eq":self.eq,
            "lt": self.lt,
            "gt": self.gt,
            "dup": self.dup,
            "exch":self.exch,
            "pop":self.pop,
            "copy":self.copy,
            "count": self.count,
            "clear":self.clear,
            "stack":self.stack,
            "dict":self.psDict,
            "string":self.string,
            "length":self.length,
            "get":self.get,
            "put":self.put,
            "getinterval":self.getinterval,
            "putinterval":self.putinterval,
            "search" : self.search,
            "begin":self.begin,
            "end":self.end,
            "def":self.psDef,
            "if":self.psIf,
            "ifelse":self.psIfelse,
            "for":self.psFor
        }
    #------- Operand Stack Helper Functions --------------
    
    """
        Helper function. Pops the top value from opstack and returns it.
    """
    def opPop(self):
        if len(self.opstack) > 0:
            x = self.opstack[len(self.opstack) - 1]
            self.opstack.pop(len(self.opstack) - 1)
            return x
        else:
            print("Error: opPop - Operand stack is empty")

    """
       Helper function. Pushes the given value to the opstack.
    """
    def opPush(self,value):
        self.opstack.append(value)

    #------- Dict Stack Helper Functions --------------
    """
       Helper function. Pops the top dictionary from dictstack and returns it.
    """  
    def dictPop(self):
        if len(self.dictstack) > 0:
            x = self.dictstack[len(self.dictstack) - 1]
            self.dictstack.pop(len(self.dictstack) - 1)
            return x
        else:
            print("Error: dictPop - Dictionary stack is empty")

    """
       Helper function. Pushes the given dictionary onto the dictstack. 
    """   
    def dictPush(self,d):
        self.dictstack.append(d)

    """
       Helper function. Adds name:value pair to the top dictionary in the dictstack.
       (Note: If the dictstack is empty, first adds an empty dictionary to the dictstack then adds the name:value to that. 
    """  
    def define(self,name, value):
        if(len(self.dictstack) == 0):
            self.dictPush({})

        if(isinstance(self.dictstack[len(self.dictstack) - 1],DictionaryValue)):
            self.dictstack[len(self.dictstack) - 1].value[name] = value
        else:
            self.dictstack[len(self.dictstack) - 1][name] = value

    """
       Helper function. Searches the dictstack for a variable or function and returns its value. 
       (Starts searching at the top of the dictstack; if name is not found returns None and prints an error message.
        Make sure to add '/' to the begining of the name.)
    """
    def lookup(self,name):
        value = None
        for d in reversed(self.dictstack):
            if isinstance(d,dict):
                value = d.get("/" + name, None)
                if value != None:
                    return value
            else:
                value = d.value.get("/" + name, None)
                if value != None:
                    return value
        
        print("Name doesn't exist")
        return value
    
    #------- Arithmetic Operators --------------

    """
       Pops 2 values from opstack; checks if they are numerical (int); adds them; then pushes the result back to opstack. 
    """  
    def add(self):
        if len(self.opstack) > 1:
            op1 = self.opPop()
            op2 = self.opPop()
            if (isinstance(op1,int) or isinstance(op1,float))  and (isinstance(op2,int) or isinstance(op2,float)):
                self.opPush(op1 + op2)
            else:
                print("Error: add - one of the operands is not a number value")
                self.opPush(op1)
                self.opPush(op2)             
        else:
            print("Error: add expects 2 operands")

    """
       Pops 2 values from opstack; checks if they are numerical (int); subtracts them; and pushes the result back to opstack. 
    """ 
    def sub(self):
        if len(self.opstack) > 1:
            op1 = self.opPop()
            op2 = self.opPop()
            if (isinstance(op1,int) or isinstance(op1,float))  and (isinstance(op2,int) or isinstance(op2,float)):
                self.opPush(op2 - op1)
            else:
                print("Error: sub - one of the operands is not a number value")
                self.opPush(op2)
                self.opPush(op1)             
        else:
            print("Error: sub expects 2 operands")

    """
        Pops 2 values from opstack; checks if they are numerical (int); multiplies them; and pushes the result back to opstack. 
    """
    def mul(self):
        if len(self.opstack) > 1:
            op1 = self.opPop()
            op2 = self.opPop()
            if (isinstance(op1,int) or isinstance(op1,float))  and (isinstance(op2,int) or isinstance(op2,float)):
                self.opPush(op1 * op2)
            else:
                print("Error: mul - one of the operands is not a number value")
                self.opPush(op1)
                self.opPush(op2)             
        else:
            print("Error: mul expects 2 operands")

    """
        Pops 2 values from stack; checks if they are int values; calculates the remainder of dividing the bottom value by the top one; 
        pushes the result back to opstack.
    """
    def mod(self):
        if len(self.opstack) > 1:
            op1 = self.opPop()
            op2 = self.opPop()
            if (isinstance(op1,int) or isinstance(op1,float))  and (isinstance(op2,int) or isinstance(op2,float)):
                self.opPush(op2 % op1)
            else:
                print("Error: mod - one of the operands is not a number value")
                self.opPush(op2)
                self.opPush(op1)             
        else:
            print("Error: mod expects 2 operands")

    """ Pops 2 values from stacks; if they are equal pushes True back onto stack, otherwise it pushes False.
          - if they are integers or booleans, compares their values. 
          - if they are StringValue values, compares the `value` attributes of the StringValue objects;
          - if they are DictionaryValue objects, compares the objects themselves (i.e., ids of the objects).
        """
    def eq(self):
        if len(self.opstack) > 1:
            op1 = self.opPop()
            op2 = self.opPop()
            if (isinstance(op1,int) or isinstance(op1,bool))  and (isinstance(op2,int) or isinstance(op2,bool)):
                self.opPush(op1 == op2)
            elif (isinstance(op1,StringValue))  and (isinstance(op2,StringValue)):
                self.opPush(op1.value == op2.value)
            elif (isinstance(op1,DictionaryValue))  and (isinstance(op2,DictionaryValue)):
                self.opPush(op1 is op2)
            else:
                print("Error: eq - one of the operands is of invalid type")
                self.opPush(op1)
                self.opPush(op2)             
        else:
            print("Error: eq expects 2 operands")

    """ Pops 2 values from stacks; if the bottom value is less than the second, pushes True back onto stack, otherwise it pushes False.
          - if they are integers or booleans, compares their values. 
          - if they are StringValue values, compares the `value` attributes of them;
          - if they are DictionaryValue objects, compares the objects themselves (i.e., ids of the objects).
    """  
    def lt(self):
        if len(self.opstack) > 1:
            op1 = self.opPop()
            op2 = self.opPop()
            if (isinstance(op1,int) or isinstance(op1,bool))  and (isinstance(op2,int) or isinstance(op2,bool)):
                self.opPush(op1 > op2)
            elif (isinstance(op1,StringValue))  and (isinstance(op2,StringValue)):
                self.opPush(op1.value > op2.value)
            elif (isinstance(op1,DictionaryValue))  and (isinstance(op2,DictionaryValue)):
                self.opPush(op1 > op2)
            else:
                print("Error: lt - one of the operands is of invalid type")
                self.opPush(op1)
                self.opPush(op2)             
        else:
            print("Error: lt expects 2 operands")


    """ Pops 2 values from stacks; if the bottom value is greater than the second, pushes True back onto stack, otherwise it pushes False.
          - if they are integers or booleans, compares their values. 
          - if they are StringValue values, compares the `value` attributes of them;
          - if they are DictionaryValue objects, compares the objects themselves (i.e., ids of the objects).
    """  
    def gt(self):
        if len(self.opstack) > 1:
            op1 = self.opPop()
            op2 = self.opPop()
            if (isinstance(op1,int) or isinstance(op1,bool))  and (isinstance(op2,int) or isinstance(op2,bool)):
                self.opPush(op1 < op2)
            elif (isinstance(op1,StringValue))  and (isinstance(op2,StringValue)):
                self.opPush(op1.value < op2.value)
            elif (isinstance(op1,DictionaryValue))  and (isinstance(op2,DictionaryValue)):
                self.opPush(op1 < op2)
            else:
                print("Error: gt - one of the operands is of invalid type")
                self.opPush(op1)
                self.opPush(op2)             
        else:
            print("Error: gt expects 2 operands")

    #------- Stack Manipulation and Print Operators --------------
    """
       This function implements the Postscript "pop operator". Calls self.opPop() to pop the top value from the opstack and discards the value. 
    """
    def pop (self):
        if (len(self.opstack) > 0):
            self.opPop()
        else:
            print("Error: pop - not enough arguments")

    """
       Prints the opstack and dictstack. The end of the list is the top of the stack. 
    """
    def stack(self):
        print(OKGREEN+"**opstack**")
        for item in reversed(self.opstack):
            print(item)
        print("-----------------------"+CEND)
        print(RED+"**dictstack**")
        for item in reversed(self.dictstack):
            print(item)
        print("-----------------------"+ CEND)


    """
       Copies the top element in opstack.
    """
    def dup(self):
        self.opPush(self.opstack[len(self.opstack) - 1])

    """
       Pops an integer count from opstack, copies count number of values in the opstack. 
    """
    def copy(self):
        length = len(self.opstack) - 1

        if length > 0:
            op = self.opPop()
            i = length - op
            temp = i
            if (isinstance(op,int)):
                while i < length and i < op+temp:
                    self.opPush(self.opstack[i])
                    i+=1
            else:
                print("Error: copy - one of the operands is not a number value")
                self.opPush(op)             
        else:
            print("Error: copy expects 1 operand")

    """
        Counts the number of elements in the opstack and pushes the count onto the top of the opstack.
    """
    def count(self):
        self.opPush(len(self.opstack))

    """
       Clears the opstack.
    """
    def clear(self):
        self.opstack.clear()
        
    """
       swaps the top two elements in opstack
    """
    def exch(self):
        if len(self.opstack) > 1:
            op1 = self.opPop()
            op2 = self.opPop()
            self.opPush(op1)
            self.opPush(op2)
                     
        else:
            print("Error: exch expects 2 operands")

    # ------- String and Dictionary creator operators --------------

    """ Creates a new empty string  pushes it on the opstack.
    Initializes the characters in the new string to \0 , i.e., ascii NUL """
    def string(self):
        string = "("
        if len(self.opstack) > 0:
            op = self.opPop()
            for i in range(0, op):
                string += '\0'
            
            self.opPush(StringValue(string + ")"))
                     
        else:
            print("Error: string expects 1 operand")
    
    """Creates a new empty dictionary  pushes it on the opstack """
    def psDict(self):
        if len(self.opstack) > 0:
            op = self.opPop()            
            self.opPush(DictionaryValue({}))
                     
        else:
            print("Error: psDict expects 1 operand")

    # ------- String and Dictionary Operators --------------
    """ Pops a string or dictionary value from the operand stack and calculates the length of it. Pushes the length back onto the stack.
       The `length` method should support both DictionaryValue and StringValue values.
    """
    def length(self):
        if len(self.opstack) > 0:
            op = self.opPop()
            if (isinstance(op,StringValue)):
                self.opPush(len(op.value) - 2)
            elif (isinstance(op,DictionaryValue)):
                self.opPush(len(op.value))
            else:
                print("Error: length - one of the operands is of invalid type")
                self.opPush(op)          
        else:
            print("Error: length expects 1 operand")


    """ Pops either:
         -  "A (zero-based) index and an StringValue value" from opstack OR 
         -  "A `name` (i.e., a key) and DictionaryValue value" from opstack.  
        If the argument is a StringValue, pushes the ascii value of the the character in the string at the index onto the opstack;
        If the argument is an DictionaryValue, gets the value for the given `name` from DictionaryValue's dictionary value and pushes it onto the opstack
    """
    def get(self):
        if len(self.opstack) > 1:
            op1 = self.opPop()
            op2 = self.opPop()
            if (isinstance(op1,int)) and (isinstance(op2,StringValue)):
                self.opPush(ord(op2.value[op1+1]))
            elif isinstance(op2,DictionaryValue):
                self.opPush(op2.value[op1])
            else:
                print("Error: get - one of the operands is of invalid type")
                self.opPush(op2)
                self.opPush(op1)             
        else:
            print("Error: get expects 2 operands")
   
    """
    Pops either:
    - "An `item`, a (zero-based) `index`, and an StringValue value from  opstack", OR
    - "An `item`, a `name`, and a DictionaryValue value from  opstack". 
    If the argument is a StringValue, replaces the character at `index` of the StringValue's string with the character having the ASCII value of `item`.
    If the argument is an DictionaryValue, adds (or updates) "name:item" in DictionaryValue's dictionary `value`.
    """
    def put(self):
        if len(self.opstack) > 2:
            op1 = self.opPop()
            op2 = self.opPop()
            op3 = self.opPop()
            if (isinstance(op2,int)) and (isinstance(op3,StringValue)):
                op3.value = op3.value[0:op2+1] + chr(op1) + op3.value[op2+2:]
            elif isinstance(op3,DictionaryValue):
                op3.value[op2] = op1
            else:
                print("Error: put - one of the operands is of invalid type")
                self.opPush(op3)
                self.opPush(op2)
                self.opPush(op1)             
        else:
            print("Error: put expects 3 operands")

    """
    getinterval is a string only operator, i.e., works only with StringValue values. 
    Pops a `count`, a (zero-based) `index`, and an StringValue value from  opstack, and 
    extracts a substring of length count from the `value` of StringValue starting from `index`,
    pushes the substring back to opstack as a StringValue value. 
    """ 
    def getinterval(self):
        if len(self.opstack) > 2:
            op1 = self.opPop()
            op2 = self.opPop()
            op3 = self.opPop()
            if (isinstance(op1,int)) and isinstance(op2,int) and (isinstance(op3,StringValue)):
                temp = "("
                for i in range(op2, op2+op1):
                    temp += op3.value[i+1]
                self.opPush(StringValue(temp + ")"))
            else:
                print("Error: getinterval - one of the operands is of invalid type")
                self.opPush(op3)
                self.opPush(op2)
                self.opPush(op1)             
        else:
            print("Error: getinterval expects 3 operands")

    """
    putinterval is a string only operator, i.e., works only with StringValue values. 
    Pops a StringValue value, a (zero-based) `index`, a `substring` from  opstack, and 
    replaces the slice in StringValue's `value` from `index` to `index`+len(substring)  with the given `substring`s value. 
    """
    def putinterval(self):
        if len(self.opstack) > 2:
            op1 = self.opPop()
            op2 = self.opPop()
            op3 = self.opPop()
            if (isinstance(op1,StringValue)) and isinstance(op2,int) and (isinstance(op3,StringValue)):
                op3.value = op3.value[0:op2+1] + str(op1)[14:-3] + op3.value[op2+len(str(op1)[14:-3])+1:]
            else:
                print("Error: putinterval - one of the operands is of invalid type")
                self.opPush(op3)
                self.opPush(op2)
                self.opPush(op1)             
        else:
            print("Error: putinterval expects 3 operands")

    """
    search is a string only operator, i.e., works only with StringValue values. 
    Pops two StringValue values: delimiter and inputstr
    if delimiter is a sub-string of inputstr then, 
       - splits inputstr at the first occurence of delimeter and pushes the splitted strings to opstack as StringValue values;
       - pushes True 
    else,
        - pushes  the original inputstr back to opstack
        - pushes False
    """
    def search(self):
        if len(self.opstack) > 1:
            op1 = self.opPop()
            op2 = self.opPop()
            if (isinstance(op1,StringValue)) and (isinstance(op2,StringValue)):
                temp = True
                for i in range(0, len(op2.value)):
                    if(op2.value[i] == op1.value[1]):
                        temp = False
                        self.opPush(StringValue("(" + op2.value[i+1:]))
                        self.opPush(op1)
                        self.opPush(StringValue(op2.value[0:i] + ")"))
                        self.opPush(True)
                        break
                
                if temp:
                    self.opPush(op2)
                    self.opPush(False)

            else:
                print("Error: search - one of the operands is of invalid type")
                self.opPush(op2)
                self.opPush(op1)             
        else:
            print("Error: search expects 2 operands")

    # ------- Operators that manipulate the dictstact --------------
    """ begin operator
        Pops a DictionaryValue value from opstack and pushes it's `value` to the dictstack."""
    def begin(self):
        self.dictPush(self.opPop())

    """ end operator
        Pops the top dictionary from dictstack."""
    def end(self):
        self.dictPop()
        
    """ Pops a name and a value from stack, adds the definition to the dictionary at the top of the dictstack. """
    def psDef(self):
        if len(self.opstack) > 1:
            op1 = self.opPop()
            op2 = self.opPop()
            if (isinstance(op2,str)):
                self.define(op2, op1)
            else:
                print("Error: psDef - one of the operands is of invalid type")
                self.opPush(op2)
                self.opPush(op1)             
        else:
            print("Error: psDef expects 2 operands")

    # ------- if/ifelse Operators --------------
    """ if operator
        Pops a CodeArrayValue object and a boolean value, if the value is True, executes (applies) the code array by calling apply.
       Will be completed in part-2. 
    """
    def psIf(self):
        if len(self.opstack) > 1:
            op1 = self.opPop()
            op2 = self.opPop()
            if (isinstance(op1,CodeArrayValue) and isinstance(op2,bool)):
                if op2 == True:
                    op1.apply(self)
            else:
                print("Error: psIf - one of the operands is of invalid type")
                self.opPush(op2)
                self.opPush(op1)             
        else:
            print("Error: psIf expects 2 operands")

    """ ifelse operator
        Pops two CodeArrayValue objects and a boolean value, if the value is True, executes (applies) the bottom CodeArrayValue otherwise executes the top CodeArrayValue.
        Will be completed in part-2. 
    """
    def psIfelse(self):
        if len(self.opstack) > 2:
            op1 = self.opPop()
            op2 = self.opPop()
            op3 = self.opPop()
            if (isinstance(op1,CodeArrayValue) and isinstance(op2,CodeArrayValue) and isinstance(op3,bool)):
                if op3 == True:
                    op2.apply(self)
                else:
                    op1.apply(self)
            else:
                print("Error: psIfelse - one of the operands is of invalid type")
                self.opPush(op3)
                self.opPush(op2)
                self.opPush(op1)             
        else:
            print("Error: psIfelse expects 3 operands")


    #------- Loop Operators --------------
    """
       Implements for operator.   
       Pops a CodeArrayValue object, the end index (end), the increment (inc), and the begin index (begin) and 
       executes the code array for all loop index values ranging from `begin` to `end`. 
       Pushes the current loop index value to opstack before each execution of the CodeArrayValue. 
       Will be completed in part-2. 
    """ 
    def psFor(self):
        if len(self.opstack) > 2:
            op1 = self.opPop()
            op2 = self.opPop()
            op3 = self.opPop()
            op4 = self.opPop()
            if (isinstance(op1,CodeArrayValue) and isinstance(op2,int) and isinstance(op3,int) and isinstance(op4,int)):
                for i in range(op4, op2+op3, op3):
                    self.opPush(i)
                    op1.apply(self)
            else:
                print("Error: psFor - one of the operands is of invalid type")
                self.opPush(op4)
                self.opPush(op3)
                self.opPush(op2)
                self.opPush(op1)             
        else:
            print("Error: psFor expects 4 operands")

    """ Cleans both stacks. """      
    def clearBoth(self):
        self.opstack[:] = []
        self.dictstack[:] = []

    """ Will be needed for part2"""
    def cleanTop(self):
        if len(self.opstack)>1:
            if self.opstack[-1] is None:
                self.opstack.pop()

