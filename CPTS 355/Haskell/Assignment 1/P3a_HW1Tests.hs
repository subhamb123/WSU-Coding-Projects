{-  To run the tests type "run" at the Haskell prompt.  -} 

module P3a_HW1tests
    where

import Test.HUnit
import Data.Char
import Data.List (sort)
import HW1

-- make_sparse tests
p3a_test1 = TestCase (assertEqual "make_sparse-test1"
                                  [0,0,0,30,0,0,0,0,0,0,100,110]
                                  (make_sparse [(3,30),(10,100),(11,110)]) )
p3a_test2 = TestCase (assertEqual "make_sparse-test2"
                                  [0,1,2,0,4,0,6,0,0,9]
                                  (make_sparse [(1,1),(2,2),(4,4),(6,6),(9,9)]) )
p3a_test3 = TestCase (assertEqual "make_sparse-test3"
                                  [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1]
                                  (make_sparse [(20,1)]) )
p3a_test4 = TestCase (assertEqual "make_sparse-test4"
                                  ([]::[Int])
                                  (make_sparse []) )

                                  
tests = TestList [
                   TestLabel "Problem 3a- test1 " p3a_test1,
                   TestLabel "Problem 3a- test2 " p3a_test2,
                   TestLabel "Problem 3a- test3 " p3a_test3,
                   TestLabel "Problem 3a- test4 " p3a_test4
                 ]

-- shortcut to run the tests
run = runTestTT  tests
