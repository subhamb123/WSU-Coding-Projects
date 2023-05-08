module Q3_tests
    where

import Test.HUnit
import Data.Char
import Data.List (sort)
import Lab2

{-concatAll and concat2Either-}
p3a_test1 = TestCase (assertEqual "test 3a-1" "enrolled in CptS-355 and CptS-322" (concatAll [["enrolled"," ","in"," "],["CptS","-","355"],[" ","and"," "],["CptS","-","322"]]) )
p3a_test2 = TestCase (assertEqual "test 3a-2" "" (concatAll [[],[]]))

p3b_test1 = TestCase (assertEqual "test 3b-1" (AString "enrolled in CptS-355 and CptS-322") (concat2Either [[AString "enrolled", AString " ", AString "in", AString " "],[AString "CptS", AString "-", AnInt 355], [AString " ", AString "and", AString " "], [AString "CptS", AString "-", AnInt 322]]) )
p3b_test2 = TestCase (assertEqual "test 3b-2" (AString "0") (concat2Either [[AString "", AnInt 0],[]]) )
p3b_test3 = TestCase (assertEqual "test 3b-3" (AString "" ) (concat2Either ([]::[[AnEither]])) )

tests = TestList [ TestLabel "Problem 3a - test1 " p3a_test1,
                   TestLabel "Problem 3a - test2 " p3a_test2,  
                   TestLabel "Problem 3b - test1 " p3b_test1,
                   TestLabel "Problem 3b - test2 " p3b_test2,
                   TestLabel "Problem 3b - test3 " p3b_test3
                 ] 

-- shortcut to run the tests
main = runTestTT  tests