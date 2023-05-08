import unittest
from HW3 import *

class P3_HW3tests(unittest.TestCase):
    "Unittest setup file. Unittest framework will run this before every test."
    def setUp(self):
        self.graph = {'A':('B',5),'B':('D',3),'C':('G',10),'D':('E',4),'E':('C',5),'F':('I',4),'G':('B',9),'H':('G',5),'I':('H',3)}


    #--- Problem 3 ----------------------------------
    def test_graph_cycle1(self):
        output = ['C', 'G', 'B', 'D', 'E', 'C']
        self.assertListEqual(graph_cycle(self.graph,'C'),output)

    def test_graph_cycle2(self):
        output = ['B', 'D', 'E', 'C', 'G', 'B']
        self.assertListEqual(graph_cycle(self.graph,'A'),output)

    def test_graph_cycle3(self):
        output = ['G', 'B', 'D', 'E', 'C', 'G']
        self.assertEqual(graph_cycle(self.graph,'F'),output)

    
if __name__ == '__main__':
    unittest.main(verbosity=2)

