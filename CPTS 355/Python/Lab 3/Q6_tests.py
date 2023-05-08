import unittest
from Lab3 import *

class Lab3_Q6_Tests(unittest.TestCase):

    # Helper function for test_apply2nextN.
    # Creates an infinite iterator representing the sequence of even numbers starting at "init"
    class OddsEvens(object):
        def __init__(self,init):
            self.current = init
        def __next__(self):
            result = self.current
            self.current += 2
            return result
        def __iter__(self):
            return self

    # Helper function for test_apply2nextN. 
    # This function assumes that the first value in L is less than or equal to N.
    def getnextN(self,L,n):
        tempL = []
        for item in L:
            tempL.append(item)
            n-=1
            if n==0: break
        return tempL

    def test_apply2nextN_test1(self):
    	#test 1
        iSequence = apply2nextN(lambda a,b:a+b, 3, iter(range(1,32)))
        self.assertEqual(iSequence.__next__(),6)
        self.assertEqual(iSequence.__next__(),15)
        self.assertEqual(iSequence.__next__(),24)
        rest = []
        for item in iSequence:
            rest.append(item)
        self.assertEqual(rest,[33, 42, 51, 60, 69, 78, 87, 31])
    
    def test_apply2nextN_test2(self):
    	#test 2
        strIter =iter('aaaabbbbccccddddeeeeffffgggghhhhjjjjkkkkllllmmmm')
        iSequence = apply2nextN(lambda a,b:a+b, 4, strIter)
        self.assertEqual(iSequence.__next__(),'aaaa')
        self.assertEqual(iSequence.__next__(),'bbbb')
        self.assertEqual(iSequence.__next__(),'cccc')
        rest = []
        for item in iSequence:
            rest.append(item)
        self.assertEqual(rest,['dddd','eeee','ffff','gggg','hhhh','jjjj','kkkk','llll','mmmm'])
    
    def test_apply2nextN_test3(self):
        #test3
        evens = self.OddsEvens(2)
        iSequence = apply2nextN(lambda a,b:a+b, 2, evens)
        self.assertEqual(iSequence.__next__(),6)
        upto100 = self.getnextN(iSequence,10)
        self.assertEqual(upto100,[14, 22, 30, 38, 46, 54, 62, 70, 78, 86])
        self.assertEqual(iSequence.__next__(),94)

if __name__ == '__main__':
    unittest.main()

