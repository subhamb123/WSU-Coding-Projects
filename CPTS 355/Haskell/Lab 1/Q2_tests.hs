module Q2_tests
    where

import Test.HUnit
import Data.Char
import Data.List (sort)
import Lab1


p2_test1 = TestCase (assertEqual "(insertEvery 3 100 [1,2,3,4,5,6,7,8,9,10])" [1,2,3,100,4,5,6,100,7,8,9,100,10] (insertEvery 3 100 [1,2,3,4,5,6,7,8,9,10]) ) 
p2_test2 = TestCase (assertEqual "(insertEvery 8 100 [1,2,3,4,5,6,7,8])" [1,2,3,4,5,6,7,8,100] (insertEvery 8 100 [1,2,3,4,5,6,7,8]))
p2_test3 = TestCase (assertEqual "(insertEvery 9 100 [1,2,3,4,5,6,7,8])" [1,2,3,4,5,6,7,8] (insertEvery 9 100 [1,2,3,4,5,6,7,8]))
p2_test4 = TestCase (assertEqual "(insertEvery 3 100 [])" [] (insertEvery 3 100 []))
p2_test5 = TestCase (assertEqual "(insertEvery 3 'a' \"123456789\")"  "123a456a789a" (insertEvery 3 'a' "123456789"))

tests = TestList [ TestLabel "Problem 2- test1" p2_test1, 
                   TestLabel "Problem 2- test2" p2_test2, 
                   TestLabel "Problem 2- test3" p2_test3,
                   TestLabel "Problem 2- test4" p2_test4,                   
                   TestLabel "Problem 2- test5" p2_test5
                 ] 
                  
-- shortcut to run the tests
main = runTestTT  tests
                  