{-  To run the tests type "run" at the Haskell prompt.  -} 

module P1a_HW1tests
    where

import Test.HUnit
import Data.Char
import Data.List (sort)
import HW1

-- count tests
p1a_test1 = TestCase (assertEqual "count-test1"
                                 3
                                 (count '5' "355-451") )
p1a_test2 = TestCase (assertEqual "count-test2"
                                 2
                                 (count [] [[],[1,2],[3,2],[5,6,7],[8],[]]) )
p1a_test3 = TestCase (assertEqual "count-test3"
                                 0
                                 (count 0 [1,2,3,4,5,6,7,8,9]) )

tests = TestList [ TestLabel "Problem 1a- test1 " p1a_test1,
                   TestLabel "Problem 1a- test2 " p1a_test2,
                   TestLabel "Problem 1a- test3 " p1a_test3
                 ]

-- shortcut to run the tests
run = runTestTT  tests
