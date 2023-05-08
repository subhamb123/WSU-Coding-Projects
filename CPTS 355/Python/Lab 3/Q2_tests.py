import unittest
from Lab3 import *

class Lab3_Q2_Tests(unittest.TestCase):
    def setUp(self):
        self.CDCdata = { 'King':{'Mar':2706,'Apr':3620,'May':1860,'Jun':2157,'July':5014,'Aug':4327,'Sep':2843},
            'Pierce':{'Mar':460,'Apr':965,'May':522,'Jun':647,'July':2470,'Aug':1776,'Sep':1266}, 
            'Snohomish':{'Mar':1301,'Apr':1145,'May':532,'Jun':568,'July':1540,'Aug':1134,'Sep':811}, 
            'Spokane':{'Mar':147,'Apr':222,'May':233,'Jun':794,'July':2412,'Aug':1530,'Sep':1751}, 
            'Whitman' : {'Apr':7,'May':5,'Jun':19,'July':51,'Aug':514,'Sep':732, 'Oct':278} }

    def test_getMonthlyCases(self):
        monthlyCases = {'Mar': {'King': 2706, 'Pierce': 460, 'Snohomish': 1301, 'Spokane': 147}, 'Apr': {'King': 3620, 'Pierce': 965, 'Snohomish': 1145, 'Spokane': 222, 'Whitman': 7}, 'May': {'King': 1860, 'Pierce': 522, 'Snohomish': 532, 'Spokane': 233, 'Whitman': 5}, 'Jun': {'King': 2157, 'Pierce': 647, 'Snohomish': 568, 'Spokane': 794, 'Whitman': 19}, 'July': {'King': 5014, 'Pierce': 2470, 'Snohomish': 1540, 'Spokane': 2412, 'Whitman': 51}, 'Aug': {'King': 4327, 'Pierce': 1776, 'Snohomish': 1134, 'Spokane': 1530, 'Whitman': 514}, 'Sep': {'King': 2843, 'Pierce': 1266, 'Snohomish': 811, 'Spokane': 1751, 'Whitman': 732}, 'Oct': {'Whitman': 278}}
        self.assertDictEqual(getMonthlyCases(self.CDCdata),monthlyCases)

if __name__ == '__main__':
    unittest.main()

