{-  To run the tests type "run" at the Haskell prompt.  -} 

module P3b_HW1tests
    where

import Test.HUnit
import Data.Char
import Data.List (sort)
import HW1

-- compress tests
p3b_test1 = TestCase (assertEqual "compress-test1"
                                  [(3,30),(10,100),(11,110)]
                                  (compress [0,0,0,30,0,0,0,0,0,0,100,110]) )
p3b_test2 = TestCase (assertEqual "compress-test2"
                                  [(1,1),(2,2),(4,4),(6,6),(9,9)]
                                  (compress [0,1,2,0,4,0,6,0,0,9]) )
p3b_test3 = TestCase (assertEqual "compress-test3"
                                  [(20,1)]
                                  (compress [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1]) )
p3b_test4 = TestCase (assertEqual "compress-test4"
                                  ([]::[(Int,Int)])
                                  (compress []) )

                                  
tests = TestList [
                   TestLabel "Problem 3b- test1 " p3b_test1,
                   TestLabel "Problem 3b- test2 " p3b_test2,
                   TestLabel "Problem 3b- test3 " p3b_test3,
                   TestLabel "Problem 3b- test4 " p3b_test4
                 ]

-- shortcut to run the tests
run = runTestTT  tests
