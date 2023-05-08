import unittest
from Lab3 import *

class Lab3_Q4_Test4(unittest.TestCase): 
    def setUp(self):
        #searchDicts inputs
        self.dictList = [{"x":1,"y":True,"z":"found"},{"x":2},{"y":False}]
        self.dictList2 = [(0,{"x":0,"y":True,"z":"zero"}), (0,{"x":1}), (1,{"y":False}), (1,{"x":3, "z":"three"}), (2,{})]

    # def test_searchDicts_test1(self):       
    #     self.assertEqual(searchDicts(self.dictList,"x"),2)

    # def test_searchDicts_test2(self):       
    #     self.assertEqual(searchDicts(self.dictList,"y"),False)
        
    # def test_searchDicts_test3(self):       
    #     self.assertEqual(searchDicts(self.dictList,"z"),"found")

    # def test_searchDicts_test4(self):       
    #     self.assertEqual(searchDicts(self.dictList,"t"),None)

    def test_searchDicts2_test1(self):
        self.assertEqual(searchDicts2(self.dictList2,"x"),1)

    def test_searchDicts2_test2(self):
        self.assertEqual(searchDicts2(self.dictList2,"y"),False)

    def test_searchDicts2_test3(self):
        self.assertEqual(searchDicts2(self.dictList2,"z"),"zero")

    def test_searchDicts2_test4(self):
        self.assertEqual(searchDicts2(self.dictList2,"t"),None)

if __name__ == '__main__':
    unittest.main()

