module P5b_HW2tests
    where

import Test.HUnit
import Data.Char
import Data.List (sort)
import HW2


int_t1 = (NODE 8 (NODE 0 (LEAF 4) (NODE 4 NULL (LEAF 9))) (NODE 0 (NODE 0 (LEAF 10) (NODE 7 NULL (LEAF 13)))  NULL))
int_t2 = (NODE 0 (NODE 10 (LEAF 4)  NULL) (NODE (-10) (NODE (-3) NULL  (NODE 10 NULL (LEAF (-3)))) (LEAF (-4))))

sum_t1_output = NODE 55 (NODE 17 (LEAF 4) (NODE 13 NULL (LEAF 9))) (NODE 30 (NODE 30 (LEAF 10) (NODE 20 NULL (LEAF 13))) NULL)
sum_t2_output = (NODE 4 (NODE 14 (LEAF 4)  NULL) (NODE (-10) (NODE 4 NULL  (NODE 7 NULL (LEAF (-3)))) (LEAF (-4))))


{- create_sumtree tests  -}
p5b_test1 = TestCase (assertEqual "create_sumtree test-1" 
                                   sum_t1_output 
                                   (create_sumtree int_t1) ) 
p5b_test2 = TestCase (assertEqual "create_sumtree  test-2" 
                                   sum_t2_output 
                                   (create_sumtree int_t2) ) 

tests = TestList [ TestLabel "Problem 5b - test1 " p5b_test1,
                   TestLabel "Problem 5b - test2 " p5b_test2
                 ]
                  

-- shortcut to run the tests
run = runTestTT  tests