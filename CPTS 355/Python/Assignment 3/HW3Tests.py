#------------------------------------------------------
#-- INCLUDE YOUR OWN TESTS IN THIS FILE
#------------------------------------------------------
import unittest
from HW3 import *

class HW3SampleTests(unittest.TestCase):
    "Unittest setup file. Unittest framework will run this before every test."
    def setUp(self):
        pass

    def sort_values(self,d):
        return dict(map(lambda t: (t[0],list(sorted(t[1]))), d.items()))
    
    #--- Problem 1(a)----------------------------------
    
    def test_aggregate_log(self):
        pass
        # Provide your own test here. Create your own input dictionary for this test.
        log_input = {'fgdfg':{'Mon':36,'Wed':0,'Sat':29},
                     'dfgd':{'Mon':3,'Fri':10},
                     'dfg':{'Sat':7}}
        output = {'Mon':39, 'Wed':0, 'Fri':10, 'Sat':36}
        self.assertDictEqual(aggregate_log(log_input),output)
    
    #--- Problem 1(b)----------------------------------
    def test_combine_dict(self):
        pass
        # Provide your own test here. Create your own input dictionary for this test .
        # You can re-use the data dictionary you created for problem-1.
        log1 = {'Mon':39, 'Wed':0, 'Fri':10, 'Sat':36}
        log2 = {'lol':55}
        output = {'Mon':39, 'Wed':0, 'Fri':10, 'Sat':36, 'lol':55}
        self.assertDictEqual(combine_dict(log1,log2),output)

    #--- Problem 1(c) ----------------------------------
    def test_merge_logs(self):
        pass
        # Provide your own test here. Create your own input dictionary for this test .
        # You can re-use the data dictionary you created for problem-1.
        log_list = [{'lol':{'Mon':3,'Wed':2,'Sat':2},'CptS360':{'Mon':3,'Tue':2,'Wed':2,'Fri':10},'CptS321':{'Tue':2,'Wed':2,'Thu':3},'CptS322':{'Tue':1,'Thu':5,'Sat':2}},
             {'CptS322':{'Mon':2},'CptS360':{'Thu':2, 'Fri':5},'CptS321':{'Mon':1, 'Sat':3}},
             {'CptS355':{'Sun':8},'CptS360':{'Fri':5},'CptS321':{'Mon':4},'CptS322':{'Sat':3}}]
        output = {'CptS355': {'Sun': 8}, 'CptS360': {'Mon': 3, 'Tue': 2, 'Wed': 2, 'Fri': 20, 'Thu': 2}, 'CptS321': {'Tue': 2, 'Wed': 2, 'Thu': 3, 'Mon': 5, 'Sat': 3}, 'CptS322': {'Tue': 1, 'Thu': 5, 'Sat': 5, 'Mon': 2}, 'lol':{'Mon':3,'Wed':2,'Sat':2}}
        self.assertDictEqual(self.sort_values(merge_logs(log_list)),self.sort_values(output))

    #--- Problem 2(a)----------------------------------
    def test_most_hours(self):
        pass
        # Provide your own test here. Create your own input dictionary for this test 
        log_input = {'CptS355': {'Mon': 3, 'Wed': 2, 'Sat': 2, 'Sun': 8}, 
                          'CptS360': {'Mon': 3, 'Tue': 2}, 
                          'CptS321': {'Tue': 2, 'Wed': 2, 'Thu': 3, 'Mon': 50, 'Sat': 3}, 
                          'CptS322': {'Tue': 16, 'Thu': 5, 'Sat': 5, 'Mon': 48}}
        output = ('CptS322', 74)
        self.assertTupleEqual(most_hours(log_input),output)
            
    #--- Problem 2(b) ----------------------------------
    def test_filter_log(self):
        pass
        # Provide your own test here. Create your own input dictionary for this test 
        log_input = {'CptS355': {'Mon': 3, 'Wed': 2, 'Sat': 2, 'Sun': 8}, 
                          'CptS360': {'Mon': 3, 'Tue': 2, 'Wed': 2, 'lol': 20, 'Thu': 2}, 
                          'CptS321': {'Tue': 2, 'Wed': 2, 'Thu': 3, 'Mon': 5, 'Sat': 3, 'lol': 45}}
        output = sorted(['CptS321'])
        self.assertListEqual(sorted(filter_log(log_input,"lol", 34)),output)

    #--- Problem 3----------------------------------
    def test_graph_cycle(self):
        pass
        # Provide your own test here.   Create your own input graph for this test 
        graph = {'A':('B',57),'B':('I',-3),'E':('A',75),'F':('I',0),'I':('A',3)}
        output = ['I', 'A', 'B', 'I']
        self.assertListEqual(graph_cycle(graph,'F'),output)

    #--- Problem 4----------------------------------
    def test_filter_iter(self):
        pass
        # Provide your own test here. Initialize the iterator with your own input.
        it = iter([19,-24,7,0,37,-6,26,-1])
        expected_output = [37,26]
        actual_output = list(filter_iter(it, lambda x: x>19))
        self.assertListEqual(actual_output, expected_output)

    #--- Problem 5----------------------------------
    def test_merge(self):
        pass
        # Provide your own test here.
        it1 = iter([0,7,25,31,77])
        it2 = iter([2,19])
        
        self.assertListEqual(merge(it1,it2, 6), [0,2,7,19])

if __name__ == '__main__':
    unittest.main()

