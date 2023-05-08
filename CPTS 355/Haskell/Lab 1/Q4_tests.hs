module Q4_tests
    where

import Test.HUnit
import Data.Char
import Data.List (sort)
import Lab1

sales = [("Amazon",[("Mon",30),("Wed",100),("Sat",200)]),("Etsy",[("Mon",50),("Tue",20),("Wed",25),("Fri",30)]),
         ("Ebay",[("Tue",60),("Wed",100),("Thu",30)]),("Etsy",[("Tue",100),("Thu",50),("Sat",20),("Tue",10)])]
         
othersales = [("AStore",[]),("MyStore",[("Mon",30),("Wed",100),("Thu",200)]),("MyStore",[("Wed",30),("Fri",100),("Sat",200)])]

p4_test1 = TestCase (assertEqual "(sumSales \"Etsy\" \"Tue\" sales)" 130  (sumSales "Etsy" "Tue" sales) ) 
p4_test2 = TestCase (assertEqual "(sumSales \"Etsy\" \"Sun\" sales)" 0  (sumSales "Etsy" "Sun" sales) ) 
p4_test3 = TestCase (assertEqual "(sumSales \"MyStore\" \"Wed\" othersales)" 130  (sumSales "MyStore" "Wed" othersales) ) 
p4_test4 = TestCase (assertEqual "(sumSales \"MyStore\" \"Mon\" othersales)" 30  (sumSales "MyStore" "Mon" othersales) ) 
p4_test5 = TestCase (assertEqual "(sumSales \"MyStore\" \"Sun\" othersales)" 0  (sumSales "MyStore" "Sun" othersales) ) 


tests = TestList [ TestLabel "Problem 4- test1" p4_test1, 
                   TestLabel "Problem 4- test2" p4_test2, 
                   TestLabel "Problem 4- test3" p4_test3,
                   TestLabel "Problem 4- test4" p4_test4, 
                   TestLabel "Problem 4- test5" p4_test5
                 ] 
                  
-- shortcut to run the tests
main = runTestTT  tests
                  