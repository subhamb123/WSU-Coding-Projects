{-  To run the tests type "run" at the Haskell prompt.  -} 

module P2_HW1tests
    where

import Test.HUnit
import Data.Char
import Data.List (sort)
import HW1

-- everyN tests
p2_test1 = TestCase (assertEqual "everyN-test1"
                                  [3,6,9,12]
                                  (everyN [1,2,3,4,5,6,7,8,9,10,11,12,13] 3) )
p2_test2 = TestCase (assertEqual "everyN-test2"
                                  "HASKELL"
                                  (everyN "hHaAsSkKeElLlL" 2))
p2_test3 = TestCase (assertEqual "everyN-test3"
                                  ([]::[Int])
                                  (everyN [] 5) )
p2_test4 = TestCase (assertEqual "everyN-test4"
                                  "haskell"
                                  (everyN "haskell" 1) )

tests = TestList [
                   TestLabel "Problem 2- test1 " p2_test1,
                   TestLabel "Problem 2- test2 " p2_test2,
                   TestLabel "Problem 2- test3 " p2_test3,
                   TestLabel "Problem 2- test4 " p2_test4
                 ]

-- shortcut to run the tests
run = runTestTT  tests
