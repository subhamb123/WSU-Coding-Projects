module Q6_tests
    where

import Test.HUnit
import Data.Char
import Data.List (sort)
import Lab1

p6_test1 = TestCase (assertEqual "(nSplit ',' 1 \"Courses:,CptS355,CptS322,CptS451,CptS321\")" (["Courses:","CptS355,CptS322,CptS451,CptS321"]) (nSplit ',' 1 "Courses:,CptS355,CptS322,CptS451,CptS321") ) 
p6_test2 = TestCase (assertEqual "(nSplit ',' 4 \"Courses:,CptS355,CptS322,CptS451,CptS321\")" (["Courses:","CptS355","CptS322","CptS451","CptS321"]) (nSplit ',' 4 "Courses:,CptS355,CptS322,CptS451,CptS321") ) 
p6_test3 = TestCase (assertEqual "(nSplit ',' 5 \"Courses:,CptS355,CptS322,CptS451,CptS321\")" (["Courses:","CptS355","CptS322","CptS451","CptS321"]) (nSplit ',' 5 "Courses:,CptS355,CptS322,CptS451,CptS321") ) 
p6_test4 = TestCase (assertEqual "(nSplit 0 4 [1,2,3,0,4,0,5,0,0,6,7,8,9,10])" ([[1,2,3],[4],[5],[],[6,7,8,9,10]]) (nSplit 0 4 [1,2,3,0,4,0,5,0,0,6,7,8,9,10]) ) 
p6_test5 = TestCase (assertEqual "(nSplit 1 4 [1,1,1,1,1,1,1,1,1])" [[],[],[],[],[1,1,1,1,1]] (nSplit 1 4 [1,1,1,1,1,1,1,1,1])) 

tests = TestList [ TestLabel "Problem 6- test1" p6_test1, 
                   TestLabel "Problem 6- test2" p6_test2,                    
                   TestLabel "Problem 6- test3" p6_test3,
                   TestLabel "Problem 6- test4" p6_test4, 
                   TestLabel "Problem 6- test5" p6_test5
                 ] 
                  
-- shortcut to run the tests
main = runTestTT  tests
                  