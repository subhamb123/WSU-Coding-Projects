module P1b_HW2tests
    where

import Test.HUnit
import Data.Char
import Data.List (sort)
import HW2

{- remove_every_tail tests 3% -}
p1b_test1 = TestCase (assertEqual "remove_every_tail test-1"  
                                  "123456789" 
                                  (remove_every_tail 3 "123a456b789c" ) )
p1b_test2 = TestCase (assertEqual "remove_every_tail test-2" 
                                  [1,2,3,4,5,6,7,8] 
                                  (remove_every_tail 8  [1,2,3,4,5,6,7,8,100]))
p1b_test3 = TestCase (assertEqual "remove_every_tail test-3" 
                                  [1,2,3,4,5,6,7,8] 
                                  (remove_every_tail 9 [1,2,3,4,5,6,7,8]))

tests = TestList [ TestLabel "Problem 1b - test1 " p1b_test1,
                   TestLabel "Problem 1b - test2 " p1b_test2,
                   TestLabel "Problem 1b - test3 " p1b_test3
                 ]
-- shortcut to run the tests
run = runTestTT  tests