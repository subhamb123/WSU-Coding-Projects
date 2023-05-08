import unittest
from Lab3 import *

class Lab3_Q1_Tests(unittest.TestCase):
    def setUp(self):
        self.CDCdata = { 'King':{'Mar':2706,'Apr':3620,'May':1860,'Jun':2157,'July':5014,'Aug':4327,'Sep':2843},
            'Pierce':{'Mar':460,'Apr':965,'May':522,'Jun':647,'July':2470,'Aug':1776,'Sep':1266}, 
            'Snohomish':{'Mar':1301,'Apr':1145,'May':532,'Jun':568,'July':1540,'Aug':1134,'Sep':811}, 
            'Spokane':{'Mar':147,'Apr':222,'May':233,'Jun':794,'July':2412,'Aug':1530,'Sep':1751}, 
            'Whitman' : {'Apr':7,'May':5,'Jun':19,'July':51,'Aug':514,'Sep':732, 'Oct':278} }

    def test_getNumCases_1 (self):
        self.assertEqual(getNumCases(self.CDCdata,['Whitman'],['Apr','May','Jun']),31)
        
    def test_getNumCases_2 (self):
        self.assertEqual(getNumCases(self.CDCdata,['King','Pierce'],['July','Aug']),13587)

if __name__ == '__main__':
    unittest.main()

