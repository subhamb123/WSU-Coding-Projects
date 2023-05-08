module Q1_tests
    where

import Test.HUnit
import Data.Char
import Data.List (sort)
import Lab2

{-merge2, merge2Tail, and mergeN-}
p1a_test1 = TestCase (assertEqual "merge2 -1" [3,1,2,2,1,3,6,5,4]  (merge2 [3,2,1,6,5,4] [1,2,3]) ) 
p1a_test2 = TestCase (assertEqual "merge2 -2" "CptS 355" (merge2 "Ct 5" "pS35") ) 
p1a_test3 = TestCase (assertEqual "merge2 -3" [1,2,3]  (merge2 [1,2,3] []) ) 

p1b_test1 = TestCase (assertEqual "merge2Tail -1" ([3,1,2,2,1,3,6,5,4])  (merge2Tail [3,2,1,6,5,4] [1,2,3]) ) 
p1b_test2 = TestCase (assertEqual "merge2Tail -2" "CptS 355" (merge2Tail "Ct 5" "pS35") ) 
p1b_test3 = TestCase (assertEqual "merge2Tail -3" [1,2,3]  (merge2Tail [1,2,3] []) ) 

p1c_test1 = TestCase (assertEqual "mergeN -1" ("A+1=a?2$B3b4C5c6D7d8E9F")  (mergeN ["ABCDEF","abcd","123456789","+=?$"]) )
p1c_test2 = TestCase (assertEqual "mergeN -2" [3,10,1,20,-3,30,2,4,5,-2,8,-1,9] (mergeN [[3,4],[-3,-2,-1],[1,2,5,8,9],[10,20,30]]) )
p1c_test3 = TestCase (assertEqual "mergeN -3" [1,2,3]  (mergeN [[],[],[1,2,3]]) )

tests = TestList [ TestLabel "Problem 1a - test1 " p1a_test1,
                   TestLabel "Problem 1a - test2 " p1a_test2,
                   TestLabel "Problem 1a - test3 " p1a_test3,
                   TestLabel "Problem 1b - test1 " p1b_test1,
                   TestLabel "Problem 1b - test2 " p1b_test2,
                   TestLabel "Problem 1b - test3 " p1b_test3,
                   TestLabel "Problem 1c - test1 " p1c_test1,
                   TestLabel "Problem 1c - test2 " p1c_test2,
                   TestLabel "Problem 1c - test3 " p1c_test3
                 ] 
                  

-- shortcut to run the tests
main = runTestTT  tests