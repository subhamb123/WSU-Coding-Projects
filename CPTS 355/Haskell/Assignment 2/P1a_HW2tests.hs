module P1a_HW2tests
    where

import Test.HUnit
import Data.Char
import Data.List (sort)
import HW2

{- remove_every tests 3% -}
p1a_test1 = TestCase (assertEqual "remove_every test-1"  
                                  "123456789" 
                                  (remove_every 3 "123a456b789c" ) )
p1a_test2 = TestCase (assertEqual "remove_every test-2" 
                                  [1,2,3,4,5,6,7,8] 
                                  (remove_every 8  [1,2,3,4,5,6,7,8,100]))
p1a_test3 = TestCase (assertEqual "remove_every test-3" 
                                  [1,2,3,4,5,6,7,8] 
                                  (remove_every 9 [1,2,3,4,5,6,7,8]))

tests = TestList [ TestLabel "Problem 1a - test1 " p1a_test1,
                   TestLabel "Problem 1a - test2 " p1a_test2,
                   TestLabel "Problem 1a - test3 " p1a_test3
                ]
-- shortcut to run the tests
run = runTestTT  tests