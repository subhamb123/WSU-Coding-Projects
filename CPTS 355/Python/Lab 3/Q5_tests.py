import unittest
from Lab3 import *

class Lab3_Q5_Test5(unittest.TestCase):  

    def test_getLongest_test1(self):
        strings = ['1',['22',['333',['4444','55555',['666666']],'7777777'],'4444'],'22']
        self.assertEqual(getLongest (strings), '7777777')

    def test_getLongest_test2(self):
        pets=[['cat',['dog','horse'],['bird',['bunny','fish']]]]
        self.assertEqual(getLongest (pets), 'horse')
    
if __name__ == '__main__':
    unittest.main()

