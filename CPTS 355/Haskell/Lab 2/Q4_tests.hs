module Q4_tests
    where

import Test.HUnit
import Data.Char
import Data.List (sort)
import Lab2

{-concat2Str -}
p4_test1 = TestCase (assertEqual "test 4-1" ("enrolled in CptS-355 and CptS-322") (concat2Str [[AString "enrolled", AString " ", AString "in", AString " "],[AString "CptS", AString "-", AnInt 355], [AString " ", AString "and", AString " "], [AString "CptS", AString "-", AnInt 322]]) )
p4_test2 = TestCase (assertEqual "test 4-2" ("0") (concat2Str [[AString "", AnInt 0],[]]) )
p4_test3 = TestCase (assertEqual "test 4-3" ("") (concat2Str ([]::[[AnEither]]) ))

tests = TestList [ TestLabel "Problem 4 - test1 " p4_test1,
                   TestLabel "Problem 4 - test2 " p4_test2,
                   TestLabel "Problem 4 - test3 " p4_test3
                 ] 
                  

-- shortcut to run the tests
main = runTestTT  tests