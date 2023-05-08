{- Two useful functions in the HUnit package are assertEqual and assertBool.
The arguments to 'assertEqual' are:
      a descriptive string
      the expected value
      the value being tested
The arguments to 'assertBool' are:
      a descriptive string
      the boolean value being tested
-}

module HUnitSampleTests
    where

import Test.HUnit
import SampleFunctions


f1_test1 = TestCase (assertEqual "nthElement [1,2,3,4,5] 4" 4 (nthElement [1,2,3,4,5] 4) ) 
f1_test2 = TestCase (assertEqual "nthElement \"CptS355-Assignment1\" 5" '3' (nthElement "CptS355-Assignment1" 5) ) 

f2_test1 = TestCase (assertEqual "allSquares [1,2,3,4,5]" [1,4,9,16,25]  (allSquares [1,2,3,4,5]) ) 
f2_test2 = TestCase (assertEqual "allSquares [10, 20, 30]" [100,400,900] (allSquares [10, 20, 30]) ) 

f3_test1 = TestCase (assertBool "isNull [1,2,3]"   (not (isNull [1,2,3])) ) 
f3_test2 = TestCase (assertBool "isNull []"  (isNull []) ) 



tests = TestList [ TestLabel "Function 1- test1 " f1_test1,
                   TestLabel "Function 1- test2 " f1_test2,
                   TestLabel "Function 2- test1 " f2_test1,
                   TestLabel "Function 2- test2 " f3_test2,
                   TestLabel "Function 3- test1 " f3_test1, 
                   TestLabel "Function 3- test2 " f3_test2
                 ] 
                  

-- shortcut to run the tests
run = runTestTT  tests