import unittest
from HW3 import *

class P2_HW3tests(unittest.TestCase):
    "Unittest setup file. Unittest framework will run this before every test."
    def setUp(self):
        self.log_input = {'CptS355': {'Mon': 3, 'Wed': 2, 'Sat': 2, 'Sun': 8}, 
                          'CptS360': {'Mon': 3, 'Tue': 2, 'Wed': 2, 'Fri': 20, 'Thu': 2}, 
                          'CptS321': {'Tue': 2, 'Wed': 2, 'Thu': 3, 'Mon': 5, 'Sat': 3}, 
                          'CptS322': {'Tue': 1, 'Thu': 5, 'Sat': 5, 'Mon': 2}}

    #--- Problem 2 ----------------------------------
    def test_most_hours(self):
        output = ('CptS360', 29)
        self.assertTupleEqual(most_hours(self.log_input),output)

    def test_filter_log1(self):
        output = sorted(['CptS360', 'CptS321'])
        self.assertListEqual(sorted(filter_log(self.log_input,"Tue", 2)),output)

    def test_filter_log2(self):
        output = sorted(['CptS355', 'CptS360', 'CptS321'])
        self.assertListEqual(sorted(filter_log(self.log_input,"Mon", 3)),output)


    def test_filter_log3(self):
        output = sorted([])
        self.assertListEqual(sorted(filter_log(self.log_input,"Wed", 3)),output)

    
if __name__ == '__main__':
    unittest.main(verbosity=2)

