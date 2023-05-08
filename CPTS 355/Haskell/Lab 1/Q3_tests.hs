module Q3_tests
    where

import Test.HUnit
import Data.Char
import Data.List (sort)
import Lab1


storelog = [("Mon",50),("Fri",20), ("Tue",20),("Fri",10),("Wed",25),("Fri",30),("Mon",5),("Mon",20),("Mon",50)]
p3_test1 = TestCase (assertEqual "(getSales \"Fri\" storelog)" 60  (getSales "Fri" storelog) ) 
p3_test2 = TestCase (assertEqual "(getSales \"Mon\" storelog)" 125  (getSales "Mon" storelog) ) 
p3_test3 = TestCase (assertEqual "(getSales \"Sat\" storelog)" 0  (getSales "Sat" storelog) ) 


tests = TestList [ TestLabel "Problem 3- test1" p3_test1, 
                   TestLabel "Problem 3- test2" p3_test2, 
                   TestLabel "Problem 3- test3" p3_test3
                 ] 
                  
-- shortcut to run the tests
main = runTestTT  tests
                  