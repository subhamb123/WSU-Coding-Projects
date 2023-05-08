module P6_HW2tests
    where

import Test.HUnit
import Data.Char
import Data.List (sort)
import HW2

fold_t1 = NODEs [NODEs [NODEs [LEAFs ["School","-","of","-","Electrical"],LEAFs ["-","Engineering","-"]],LEAFs ["and","-","Computer","-"]],LEAFs ["Science"],LEAFs ["-WSU"]]
fold_t2 = NODEs [ NODEs  [ LEAFs [1,2,3],LEAFs [4,5], NODEs [LEAFs [6], LEAFs []] ], NODEs [], LEAFs [7,8], NODEs [LEAFs [], LEAFs []] ]


-----------------------------------------------------------     
{- list_tree tests  -}
p6_test1 = TestCase (assertEqual "list_tree test-1"  
                                   "School-of-Electrical-Engineering-and-Computer-Science-WSU"
                                   (list_tree (++) "" fold_t1) ) 
p6_test2 = TestCase (assertEqual "list_tree test-2" 
                                   8 
                                   (list_tree max 0 fold_t2) ) 
p6_test3 = TestCase (assertEqual "list_tree test-3" 
                                   36 
                                   (list_tree (+) 0 fold_t2) )                             

tests = TestList [ TestLabel "Problem 6 - test1 " p6_test1,
                   TestLabel "Problem 6 - test2 " p6_test2,
                   TestLabel "Problem 6 - test3 " p6_test3
                 ] 
                  

-- shortcut to run the tests
run = runTestTT  tests