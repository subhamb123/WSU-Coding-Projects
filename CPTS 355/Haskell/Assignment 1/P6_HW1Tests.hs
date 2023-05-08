{-  To run the tests type "run" at the Haskell prompt.  -}

module P6_HW1tests
    where

import Test.HUnit
import Data.Char
import Data.List (sort)
import HW1

-- group_sum  tests

p6_test1 = TestCase (assertEqual "(group_sum-test1)"
                                  [[1,2,3,4],[5,6,7],[8,9,10,11],[12,13,14,15,16],[17]] 
                                  (group_sum [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17] 10) )
p6_test2 = TestCase (assertEqual "(group_sum-test2)"
                                  [[],[12],[10,1,3,4,7,11],[22,2,5,40],[100,4]]
                                  (group_sum [12,10,1,3,4,7,11,22,2,5,40,100,4] 10) )
p6_test3 = TestCase (assertEqual "(group_sum-test3)"
                                  [[],[5,-2,-3,4,-5,6],[7,8],[9,10,11],[12,-13,14,15,16,20]]
                                  (group_sum [5,-2,-3,4,-5,6,7,8,9,10,11,12,-13,14,15,16,20] 4) )

tests = TestList [
                   TestLabel "Problem 5- test1 " p6_test1,
                   TestLabel "Problem 5- test2 " p6_test2,
                   TestLabel "Problem 5- test3 " p6_test3
                 ]

-- shortcut to run the tests
run = runTestTT  tests
