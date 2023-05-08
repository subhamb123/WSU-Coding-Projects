module P4b_HW2tests
    where

import Test.HUnit
import Data.Char
import Data.List (sort)
import HW2

{- add_nested_lengths tests -}
p4b_test1 = TestCase (assertEqual "add_nested_lengths test-1" 
                                   (INCH 70)
                                   (add_nested_lengths [[INCH (-5),INCH 10],[YARD (-1), YARD 2,FOOT 2],[INCH 5],[]]) ) 
p4b_test2 = TestCase (assertEqual "add_nested_lengths  test-2" 
                                   (INCH 0)
                                   (add_nested_lengths [[INCH 5,FOOT 10],[FOOT (-10),YARD 5],[YARD (-5), INCH (-5)]]) ) 
p4b_test3 = TestCase (assertEqual "add_nested_lengths  test-3" 
                                   (INCH 262)
                                   (add_nested_lengths [[YARD 2, FOOT 1], [YARD 1, FOOT 2, INCH 10],[YARD 3]]) ) 

tests = TestList [ TestLabel "Problem 4b - test1 " p4b_test1,
                   TestLabel "Problem 4b - test2 " p4b_test2,  
                   TestLabel "Problem 4b - test3 " p4b_test3
                 ] 
                  

-- shortcut to run the tests
run = runTestTT  tests