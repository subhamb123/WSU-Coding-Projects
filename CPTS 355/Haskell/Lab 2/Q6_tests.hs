module Q6_tests
    where

import Test.HUnit
import Data.Char
import Data.List (sort)
import Lab2

{-printInfix -}

-- Sample Tree Integer examples given in the lab prompt; 
exprtree1 =  (ENODE Mul (ENODE Sub (ENODE Add (ELEAF 4) (ELEAF 5)) (ELEAF 6)) (ENODE Sub (ELEAF 10) (ELEAF 8)))
exprtree2 = (ENODE Add (ELEAF 10) (ENODE Sub (ELEAF 50) (ENODE Mul (ELEAF 3) (ELEAF 10))))

p6_test1 = TestCase (assertEqual "printInfix -1" "(((4 `Add` 5) `Sub` 6) `Mul` (10 `Sub` 8))" (printInfix  exprtree1) )
p6_test2 = TestCase (assertEqual "printInfix -2" "(10 `Add` (50 `Sub` (3 `Mul` 10)))" (printInfix  exprtree2) )
p6_test3 = TestCase (assertEqual "printInfix -3" "4" (printInfix  (ELEAF 4)) )

tests = TestList [ TestLabel "Problem 6 - test1 " p6_test1,
                   TestLabel "Problem 6 - test2 " p6_test2,
                   TestLabel "Problem 6 - test3 " p6_test3
                 ] 
                  
-- shortcut to run the tests
main = runTestTT  tests