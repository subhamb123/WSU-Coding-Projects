module P4a_HW2tests
    where

import Test.HUnit
import Data.Char
import Data.List (sort)
import HW2

{- sum_nested tests 8% -}
p4a_test1 = TestCase (assertEqual "add_lengths test-1" 
                                   (INCH 5)
                                   (add_lengths  (INCH (-5)) (INCH 10)) ) 
p4a_test2 = TestCase (assertEqual "add_lengths  test-2" 
                                   (INCH 125)
                                   (add_lengths  (INCH 5) (FOOT 10)) ) 
p4a_test3 = TestCase (assertEqual "add_lengths  test-3" 
                                   (INCH 46)
                                   (add_lengths  (YARD 1) (INCH 10)) ) 

tests = TestList [ TestLabel "Problem 4a - test1 " p4a_test1,
                   TestLabel "Problem 4a - test2 " p4a_test2,  
                   TestLabel "Problem 4a - test3 " p4a_test3
                 ] 
                  

-- shortcut to run the tests
run = runTestTT  tests