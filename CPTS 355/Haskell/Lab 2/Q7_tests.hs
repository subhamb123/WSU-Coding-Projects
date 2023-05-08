module Q7_tests
    where

import Test.HUnit
import Data.Char
import Data.List (sort)
import Lab2

{-createRTree -}

-- Sample Tree Integer examples given in the lab prompt; 
exprtree1 =  (ENODE Mul (ENODE Sub (ENODE Add (ELEAF 4) (ELEAF 5)) (ELEAF 6)) (ENODE Sub (ELEAF 10) (ELEAF 8)))
exprtree2 = (ENODE Add (ELEAF 10) (ENODE Sub (ELEAF 50) (ENODE Mul (ELEAF 3) (ELEAF 10))))

-- The createRTree should return the following "ResultTree" values for the above "ExprTree"s
resulttree1 = RNODE 6 (RNODE 3 (RNODE 9 (RLEAF 4) (RLEAF 5)) (RLEAF 6)) (RNODE 2 (RLEAF 10) (RLEAF 8))
resulttree2 = RNODE 30 (RLEAF 10) (RNODE 20 (RLEAF 50) (RNODE 30 (RLEAF 3) (RLEAF 10)))

p7_test1 = TestCase (assertEqual "createRTree - 1" (resulttree1) (createRTree exprtree1) )
p7_test2 = TestCase (assertEqual "createRTree - 2" (resulttree2) (createRTree exprtree2) )
p7_test3 = TestCase (assertEqual "createRTree - 3" (RLEAF 4) (createRTree (ELEAF 4)) )


tests = TestList [ TestLabel "Problem 7 - test1 " p7_test1,
                   TestLabel "Problem 7 - test2 " p7_test2,
                   TestLabel "Problem 7 - test3 " p7_test3
                 ] 
                  

-- shortcut to run the tests
main = runTestTT  tests