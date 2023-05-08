{-  To run the tests type "run" at the Haskell prompt.  -} 

module P1c_HW1tests
    where

import Test.HUnit
import Data.Char
import Data.List (sort)
import HW1

-- bag_diff tests
p1c_test1 = TestCase (assertEqual "bag_diff-test1"
                                 (sort [2,3,3,4,4,4,5,5,5,5,6,6,6,6,6,6])
                                 (sort $ bag_diff [1,2,2,3,3,3,4,4,4,4,5,5,5,5,5,6,6,6,6,6,6] [1,2,3,4,5,7,7]) )
p1c_test2 = TestCase (assertEqual "bag_diff-test2"
                                 (sort [3,4,4,5,5,5,5,7])
                                 (sort $ bag_diff [1,2,2,3,3,3,6,7,4,4,4,4,5,5,5,5,5,6,6] [1,1,2,2,3,3,4,4,5,6,6,6]) )
p1c_test3 = TestCase (assertEqual "bag_diff-test3"
                                 []
                                 (sort $ bag_diff [6,2,2,3,5,3,6,7,4,4,5,4,5,5,4,5,3,1,6] [1,2,2,3,3,3,6,7,4,4,4,4,5,5,5,5,5,6,6]) )
p1c_test4 = TestCase (assertEqual "bag_diff-test4"
                                 (sort "testing myuncon")
                                 (sort $ bag_diff "testing my function" "fit ") )


tests = TestList [ TestLabel "Problem 1c- test1 " p1c_test1,
                   TestLabel "Problem 1c- test2 " p1c_test2,
                   TestLabel "Problem 1c- test3 " p1c_test3,
                   TestLabel "Problem 1c- test4 " p1c_test4
                 ]

-- shortcut to run the tests
run = runTestTT  tests
