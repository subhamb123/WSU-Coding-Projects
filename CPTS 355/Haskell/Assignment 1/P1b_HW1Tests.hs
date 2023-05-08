{-  To run the tests type "run" at the Haskell prompt.  -} 

module P1b_HW1tests
    where

import Test.HUnit
import Data.Char
import Data.List (sort)
import HW1

-- diff tests
p1b_test1 = TestCase (assertEqual "diff-test1"
                                 (sort [6,6,6,6,6,6])
                                 (sort $ diff [1,2,2,3,3,3,4,4,4,4,5,5,5,5,5,6,6,6,6,6,6] [1,2,3,4,5,7,7]) )
p1b_test2 = TestCase (assertEqual "diff-test2"
                                 [7]
                                 (sort $ diff [1,2,2,3,3,3,6,7,4,4,4,4,5,5,5,5,5,6,6] [1,1,2,2,3,3,4,4,5,6,6,6]) )
p1b_test3 = TestCase (assertEqual "diff-test3"
                                 []
                                 (sort $ diff [6,2,2,3,5,3,6,7,4,4,5,4,5,5,4,5,3,1,6] [1,2,2,3,3,3,6,7,4,4,4,4,5,5,5,5,5,6,6]) )

tests = TestList [ TestLabel "Problem 1b- test1 " p1b_test1,
                   TestLabel "Problem 1b- test2 " p1b_test2,
                   TestLabel "Problem 1b- test3 " p1b_test3
                 ]

-- shortcut to run the tests
run = runTestTT  tests
