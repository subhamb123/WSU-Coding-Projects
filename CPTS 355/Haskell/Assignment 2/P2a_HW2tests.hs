module P2a_HW2tests
    where

import Test.HUnit
import Data.Char
import Data.List (sort)
import HW2

{- get_outof_range tests 3% -}
p2a_test1 = TestCase (assertEqual "get_outof_range test-1"  
                                  [10,-10] 
                                  (get_outof_range (-5) 5 [10,5,0,1,2,-5,-10] ) )
p2a_test2 = TestCase (assertEqual "get_outof_range test-2" 
                                  [1,2,3,7,8,9,10] 
                                  (get_outof_range 4 6  [1,2,3,4,5,6,7,8,9,10]))
p2a_test3 = TestCase (assertEqual "get_outof_range test-3" 
                                  "-355" 
                                  (get_outof_range 'A' 'z' "CptS-355"))                                  

tests = TestList [ TestLabel "Problem 2a - test1 " p2a_test1,
                   TestLabel "Problem 2a - test2 " p2a_test2,
                   TestLabel "Problem 2a - test3 " p2a_test3
                 ] 

-- shortcut to run the tests
run = runTestTT  tests