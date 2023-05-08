module Q1_tests
    where

import Test.HUnit
import Data.Char
import Data.List (sort)
import Lab1

p1_test1 = TestCase (assertEqual "(insert 3 'a' \"123456789\")"  "123a456789" (insert 3 'a' "123456789" ) )
p1_test2 = TestCase (assertEqual "(insert 8 100 [1,2,3,4,5,6,7,8])" [1,2,3,4,5,6,7,8,100] (insert 8 100 [1,2,3,4,5,6,7,8]))
p1_test3 = TestCase (assertEqual "(insert 9 100 [1,2,3,4,5,6,7,8])" [1,2,3,4,5,6,7,8] (insert 9 100 [1,2,3,4,5,6,7,8]))
p1_test4 = TestCase (assertEqual "(insert 3 100 [])" [] (insert 3 100 []))
p1_test5 = TestCase (assertEqual "(insert 0 'C' \"ptS355\")" "CptS355" (insert 0 'C' "ptS355"))

tests = TestList [ TestLabel "Problem 1- test1" p1_test1,
                   TestLabel "Problem 1- test2" p1_test2,  
                   TestLabel "Problem 1- test3" p1_test3,  
                   TestLabel "Problem 1- test4" p1_test4,  
                   TestLabel "Problem 1- test4" p1_test4  
                 ] 
                  
-- shortcut to run the tests
main = runTestTT  tests
                  