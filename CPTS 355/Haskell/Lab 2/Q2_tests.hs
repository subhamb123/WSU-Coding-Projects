module Q2_tests
    where

import Test.HUnit
import Data.Char
import Data.List (sort)
import Lab2

{-cont and histogram-}
p2a_test1 = TestCase (assertEqual "count -1" 2 (count [] [[],[1],[1,2],[]]) ) 
p2a_test2 = TestCase (assertEqual "count -2" 0 (count (-5) [1,2,3,4,5,6,7]) ) 
p2a_test3 = TestCase (assertEqual "count -3" 5 (count 'i' "incomprehensibilities") ) 

p2b_test1 = TestCase (assertEqual "histogram -1" (sort [([1,2],1),([1],2),([],3)]) (sort (histogram [[],[1],[1,2],[1],[],[]])) )
p2b_test2 = TestCase (assertEqual "histogram -2" (sort [('c',1),('d',1),('m',2),('i',1),('a',4)]) (sort (histogram "macadamia")) )
p2b_test3 = TestCase (assertEqual "histogram -3" (sort [('1',1),('2',2),('3',3),('4',4),('5',5)]) (sort (histogram (show 122333444455555))) )

tests = TestList [ TestLabel "Problem 2a - test1 " p2a_test1,
                   TestLabel "Problem 2a - test2 " p2a_test2,  
                   TestLabel "Problem 2a - test3 " p2a_test3,
                   TestLabel "Problem 2b - test1 " p2b_test1,
                   TestLabel "Problem 2b - test2 " p2b_test2,  
                   TestLabel "Problem 2b - test3 " p2b_test3
                 ] 
                  

-- shortcut to run the tests
main = runTestTT  tests