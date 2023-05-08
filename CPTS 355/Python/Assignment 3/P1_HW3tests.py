import unittest
from HW3 import *

class P1_HW3tests(unittest.TestCase):
    "Unittest setup file. Unittest framework will run this before every test."
    def setUp(self):
        pass

    def sort_values(self,d):
        return dict(map(lambda t: (t[0],list(sorted(t[1]))), d.items()))

    #--- Problem 1a----------------------------------
    def test_aggregate_log(self):
        log_input = {'CptS355':{'Mon':3,'Wed':2,'Sat':2},
                     'CptS360':{'Mon':3,'Tue':2,'Wed':2,'Fri':10},
                     'CptS321':{'Tue':2,'Wed':2,'Thu':3},
                     'CptS322':{'Tue':1,'Thu':5,'Sat':2}}
        output = {'Fri': 10, 'Mon': 6, 'Sat': 4, 'Thu': 8, 'Tue': 5, 'Wed': 6}
        self.assertDictEqual(aggregate_log(log_input),output)

    #--- Problem 1b----------------------------------
    def test_combine_dict(self):
        log1 = {'Mon':3,'Wed':2,'Sat':2}
        log2 = {'Mon':3,'Tue':2,'Wed':2,'Fri':10}
        output = {'Mon': 6, 'Wed': 4, 'Sat': 2, 'Tue': 2, 'Fri': 10}
        self.assertDictEqual(combine_dict(log1,log2),output)
        #make sure input dictionaries are not changed. 
        self.assertDictEqual(log1, {'Mon':3,'Wed':2,'Sat':2})
        self.assertDictEqual(log2, {'Mon':3,'Tue':2,'Wed':2,'Fri':10})


    #--- Problem 1c----------------------------------
    def test_merge_logs(self):
        log_list_backup = [{'CptS355':{'Mon':3,'Wed':2,'Sat':2},'CptS360':{'Mon':3,'Tue':2,'Wed':2,'Fri':10},'CptS321':{'Tue':2,'Wed':2,'Thu':3},'CptS322':{'Tue':1,'Thu':5,'Sat':2}},
             {'CptS322':{'Mon':2},'CptS360':{'Thu':2, 'Fri':5},'CptS321':{'Mon':1, 'Sat':3}},
             {'CptS355':{'Sun':8},'CptS360':{'Fri':5},'CptS321':{'Mon':4},'CptS322':{'Sat':3}}]
        log_list = [{'CptS355':{'Mon':3,'Wed':2,'Sat':2},'CptS360':{'Mon':3,'Tue':2,'Wed':2,'Fri':10},'CptS321':{'Tue':2,'Wed':2,'Thu':3},'CptS322':{'Tue':1,'Thu':5,'Sat':2}},
             {'CptS322':{'Mon':2},'CptS360':{'Thu':2, 'Fri':5},'CptS321':{'Mon':1, 'Sat':3}},
             {'CptS355':{'Sun':8},'CptS360':{'Fri':5},'CptS321':{'Mon':4},'CptS322':{'Sat':3}}]
        output = {'CptS355': {'Mon': 3, 'Wed': 2, 'Sat': 2, 'Sun': 8}, 'CptS360': {'Mon': 3, 'Tue': 2, 'Wed': 2, 'Fri': 20, 'Thu': 2}, 'CptS321': {'Tue': 2, 'Wed': 2, 'Thu': 3, 'Mon': 5, 'Sat': 3}, 'CptS322': {'Tue': 1, 'Thu': 5, 'Sat': 5, 'Mon': 2}}
        self.assertDictEqual(self.sort_values(merge_logs(log_list)),self.sort_values(output))
        self.assertListEqual(log_list,log_list_backup)




if __name__ == '__main__':
    unittest.main(verbosity=2)
