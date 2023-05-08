import unittest
from HW3 import *

# ----- Helper classes ------
class Numbers():
    def __init__(self,init):
        self.current = init
    def __next__(self):
        result = self.current
        self.current += 1
        return result
    def __iter__(self):
        return self

class Letters():
    def __init__(self,init):
        self.current = init
    def __next__(self):
        result = self.current
        self.current = chr(ord(self.current)+1)
        return result
    def __iter__(self):
        return self
    
class P4_HW3tests(unittest.TestCase):
    "Unittest setup file. Unittest framework will run this before every test."
    def setUp(self):
        pass
        
    #--- Problem 4----------------------------------
    def test_filter_iter1(self):
        it = iter([-1,-2,7,-3,-2,4,5,3,-2,0,3,6,2,-1])
        expected_output = [7,4,5,3,3,6,2]
        actual_output = list(filter_iter(it, lambda x: x>0))  #convert the iterator output to list
        self.assertListEqual(actual_output, expected_output)

    def test_filter_iter2(self):
        it2 = filter_iter(Numbers(-20), lambda x: x>0 and x%5==1)  # it1 represents am infinite sequence
        self.assertEqual(next(it2), 1)
        self.assertEqual(next(it2), 6)
        count = 20
        buf = []
        while count>0:  # get the next 20 values from it1
            buf.append(next(it2))
            count -= 1
        expected_output = [11,16,21,26,31,36,41,46,51,56,61,66,71,76,81,86,91,96,101,106]
        self.assertListEqual(buf, expected_output)

    def test_filter_iter3(self):
        it2 = filter_iter(Letters('a'), lambda x: x not in "acgjlmnpqrxy")   # it2 represents am infinite sequence
        self.assertEqual(next(it2), 'b')
        self.assertEqual(next(it2), 'd')    
        count = 12
        buf = []
        while count > 0: # get the next 12 values from it1
            buf.append(next(it2))
            count -= 1
        expected_output = ['e','f','h','i','k','o','s','t','u','v','w','z']
        self.assertListEqual(buf, expected_output)


if __name__ == '__main__':
    unittest.main(verbosity=2)

