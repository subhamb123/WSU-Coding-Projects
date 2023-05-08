{-  To run the tests type "run" at the Haskell prompt.  -}

module P4_HW1tests
    where

import Test.HUnit
import Data.Char
import Data.List (sort)
import HW1

-- added_sums tests
p4_test1 = TestCase (assertEqual "added_sums-test1"
                                  ([1,3,6,10,15,21,28,36,45,55])
                                  (added_sums [1,2,3,4,5,6,7,8,9,10]) )
p4_test2 = TestCase (assertEqual "added_sums-test2"
                                  ([0,-2,1,5,1,0,2])
                                  (added_sums [0,-2,3,4,-4,-1,2]) )
p4_test3 = TestCase (assertEqual "added_sums-test3"
                                  ([])
                                  (added_sums []) )


tests = TestList [
                   TestLabel "Problem 4- test1 " p4_test1,
                   TestLabel "Problem 4- test2 " p4_test2,
                   TestLabel "Problem 4- test3 " p4_test3
                 ]

-- shortcut to run the tests
run = runTestTT  tests
