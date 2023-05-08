module P2b_HW2tests
    where

import Test.HUnit
import Data.Char
import Data.List (sort)
import HW2

{- count_outof_range tests 3% -}
p2b_test1 = TestCase (assertEqual "count_outof_range test-1"  
                                  8
                                  (count_outof_range (-5) 5 [[10,5,0,1,2,-5,-10],[4,2,-1,3,-4,8,5,9,4,10],[-5,-6,7,8]] ) )
p2b_test2 = TestCase (assertEqual "count_outof_range test-2" 
                                  7 
                                  (count_outof_range 'A' 'z' ["Cpt S","-","355",":","HW2"]))
p2b_test3 = TestCase (assertEqual "count_outof_range test-3" 
                                  10
                                  (count_outof_range 1 1 [[4,1],[2,-1,3,-4],[8,0,1,5,9,4]]))

tests = TestList [ TestLabel "Problem 2b - test1 " p2b_test1,
                   TestLabel "Problem 2b - test2 " p2b_test2,
                   TestLabel "Problem 2b - test3 " p2b_test3
                 ] 

-- shortcut to run the tests
run = runTestTT  tests