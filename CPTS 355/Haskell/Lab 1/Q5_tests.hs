module Q5_tests
    where

import Test.HUnit
import Data.Char
import Data.List (sort)
import Lab1

p5_test1 = TestCase (assertEqual "(split ',' \"Courses:,CptS355,CptS322,CptS451,CptS321\")" ["Courses:","CptS355","CptS322","CptS451","CptS321"] (split ',' "Courses:,CptS355,CptS322,CptS451,CptS321")) 
p5_test2 = TestCase (assertEqual "(split 0  [1,2,3,0,4,0,5,0,0,6,7,8,9,10])" [[1,2,3],[4],[5],[],[6,7,8,9,10]] (split 0  [1,2,3,0,4,0,5,0,0,6,7,8,9,10])) 
p5_test3 = TestCase (assertEqual "(split 1  [1,1,1,1,1,1,1,1,1])" [[],[],[],[],[],[],[],[],[]] (split 1  [1,1,1,1,1,1,1,1,1])) 
p5_test4 = TestCase (assertEqual "(split '-'  \"CptS-355-?\"" ["CptS","355","?"] (split '-' "CptS-355-?")) 

tests = TestList [ TestLabel "Problem 5- test1" p5_test1, 
                   TestLabel "Problem 5- test2" p5_test2, 
                   TestLabel "Problem 5- test3" p5_test3, 
                   TestLabel "Problem 5- test4" p5_test4 
                 ] 
                  
-- shortcut to run the tests
main = runTestTT  tests
                  