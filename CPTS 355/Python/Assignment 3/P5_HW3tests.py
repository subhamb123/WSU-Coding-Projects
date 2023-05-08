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
    
class P5_HW3tests(unittest.TestCase):
    "Unittest setup file. Unittest framework will run this before every test."
    def setUp(self):
        pass
        
    #--- Problem 5----------------------------------
    def test_merge1(self):
        it1 = filter_iter(Numbers(-20), lambda x: x>0 and x%2==0)
        it2 = filter_iter(Numbers(1), lambda x: x%3==0)
        
        # first call to merge
        self.assertListEqual(merge(it1,it2, 10), [2,3,4,6,6,8,9,10,12,12])
        # second call to merge ; iterator will remember its position; 
        # note that 14 and 15 will be skipped since previous merge call consumed them but didn't include them in the output
        self.assertListEqual(merge(it1,it2, 5), [16,18,18,20,21])
        self.assertListEqual(merge(it1,it2, 5), [24,26,27,28,30])

    #--- Problem 5----------------------------------
    def test_merge2(self):
        it1 = iter([2,3,5,7,11,13,17,19])
        it2 = filter_iter(Numbers(1), lambda x: x%3==0)
        
        # first call to merge
        self.assertListEqual(merge(it1,it2, 5), [2,3,3,5,6])
        # second call to merge ; iterator will remember its position; 
        # note that 7 and 9 will be skipped since previous merge call consumed them but didn't include them in the output
        self.assertListEqual(merge(it1,it2, 2), [11,12])
        #reached to the end of the first sequence, so merge will return the remaining merged output. 
        self.assertListEqual(merge(it1,it2, 5), [17,18,19])
        #reached to the end of the first sequence, so merge will return []. 
        self.assertListEqual(merge(it1,it2, 4), [])
   

if __name__ == '__main__':
    unittest.main(verbosity=2)

