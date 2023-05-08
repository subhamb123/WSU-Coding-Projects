module P5a_HW2tests
    where

import Test.HUnit
import Data.Char
import Data.List (sort)
import HW2

-- Sample Tree Int examples given in the assignment prompt; make sure to provide your own tree examples in HW2Tests.hs file.
-- Your trees should have minimum 4 levels (including the leaves). 

int_t1 = (NODE 8 (NODE 0 (LEAF 4) (NODE 4 NULL (LEAF 9))) (NODE 0 (NODE 0 (LEAF 10) (NODE 7 NULL (LEAF 13)))  NULL))
int_t2 = (NODE 0 (NODE 10 (LEAF 4)  NULL) (NODE (-10) (NODE (-3) NULL  (NODE 10 NULL (LEAF (-3)))) (LEAF (-4))))

{- sum_tree tests  -}
p5a_test1 = TestCase (assertEqual "sum_tree test-1" 
                                   55 
                                   (sum_tree int_t1) ) 
p5a_test2 = TestCase (assertEqual "sum_tree  test-2" 
                                   4 
                                   (sum_tree int_t2) ) 

tests = TestList [ TestLabel "Problem 5a - test1 " p5a_test1,
                   TestLabel "Problem 5a - test2 " p5a_test2
                 ]
                  

-- shortcut to run the tests
run = runTestTT  tests