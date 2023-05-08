module Q5_tests
    where

import Test.HUnit
import Data.Char
import Data.List (sort)
import Lab2

{-evaluateTree -}

-- Sample Tree Integer examples given in the lab prompt; 
exprtree1 =  (ENODE Mul (ENODE Sub (ENODE Add (ELEAF 4) (ELEAF 5)) (ELEAF 6)) (ENODE Sub (ELEAF 10) (ELEAF 8)))
exprtree2 = (ENODE Add (ELEAF 10) (ENODE Sub (ELEAF 50) (ENODE Mul (ELEAF 3) (ELEAF 10))))

p5_test1 = TestCase (assertEqual "evaluateTree -1" 6 (evaluateTree exprtree1) )
p5_test2 = TestCase (assertEqual "evaluateTree -2" 30 (evaluateTree exprtree2) )
p5_test3 = TestCase (assertEqual "evaluateTree -3" 4 (evaluateTree (ELEAF 4)) )

tests = TestList [ TestLabel "Problem 5 - test1 " p5_test1,
                   TestLabel "Problem 5 - test2 " p5_test2,
                   TestLabel "Problem 5 - test3 " p5_test3
                 ] 
                  

-- shortcut to run the tests
main = runTestTT  tests