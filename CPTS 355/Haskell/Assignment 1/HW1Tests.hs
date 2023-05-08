{- Example of using the HUnit unit test framework.  See  http://hackage.haskell.org/package/HUnit for additional documentation.
To run the tests type "run" at the Haskell prompt.  -} 

module HW1Tests
    where

import Test.HUnit
import Data.Char
import Data.List (sort)
import HW1

routes_test = [("Lentil",["Chinook", "Orchard", "Valley", "Emerald", "Providence", "Stadium", "Walmart", "Bishop", "Derby", "Dilke"]), 
   ("Wheat",["Chinook", "Walmart", "PorchLight", "Campus"]), 
   ("Silver",["TransferStation", "PorchLight", "Main"]),
   ("Coffee",["TransferStation", "Grand", "Main", "Visitor", "Stadium", "Spark", "CUB"])]    

-- P1(a) count tests  
p1a_test1 = TestCase (assertEqual "count-test1"
                                 6
                                 (count 'a' "abjfakaaiaa") )

p1a_test2 = TestCase (assertEqual "count-test2"
                                 1
                                 (count [] [[],[1,2],[8]]) )

-- P1(b) diff tests
p1b_test1 = TestCase (assertEqual "diff-test1"
                                 (sort [6,6,6,6,6,6])
                                 (sort $ diff [9,1,2,2,3,3,3,4,4,4,4,5,5,5,5,5,6,6,6,6,6,6] [1,2,3,4,5,7,7,9]) )
p1b_test2 = TestCase (assertEqual "diff-test2"
                                 (sort [7,9])
                                 (sort $ diff [1,2,2,3,3,3,6,7,4,4,4,4,5,5,5,5,9,5,6,6] [6,8,1,1,2,2,3,3,4,4,5,6,6,6]) )

-- P1(c) bag_diff tests
p1c_test1 = TestCase (assertEqual "bag_diff-test1"
                                 (sort [2,3,3,4,4,4,5,5,5,5,6,6,6,6,6,6])
                                 (sort $ bag_diff [1,2,2,3,3,3,4,4,4,4,5,5,5,5,5,6,6,6,6,6,6,9] [9,9,1,2,3,4,5,7,7]) )
p1c_test2 = TestCase (assertEqual "bag_diff-test2"
                                 (sort [3,4,4,5,5,5,5,7,8,8,9])
                                 (sort $ bag_diff [9,1,2,2,3,3,3,6,8,8,8,7,4,4,4,4,5,5,5,5,5,6,6] [1,1,2,2,3,8,3,4,4,5,6,6,6]) )

-- P2  everyN tests
p2_test1 = TestCase (assertEqual "everyN-test1"
                                  [4,8,12]
                                  (everyN [1,2,3,4,5,6,7,8,9,10,11,12,13] 4) )
p2_test2 = TestCase (assertEqual "everyN-test2"
                                  "aSeL"
                                  (everyN "hHaAsSkKeElLlL" 3))

-- P3(a) make_sparse tests
p3a_test1 = TestCase (assertEqual "make_sparse-test1"
                                  [5,0,0,100]
                                  (make_sparse [(0,5),(3,100)]) )
p3a_test2 = TestCase (assertEqual "make_sparse-test2"
                                  [0,10,20,21]
                                  (make_sparse [(1,10),(2,20),(3,21)]) )

-- P3(b) compress tests
p3b_test1 = TestCase (assertEqual "compress-test1"
                                  [(0,5),(3,100)]
                                  (compress [5,0,0,100]) )
p3b_test2 = TestCase (assertEqual "compress-test2"
                                  [(1,21)]
                                  (compress [0,21]) )

-- P4 added_sums tests
p4_test1 = TestCase (assertEqual "added_sums-test1"
                                  ([8,9,4,10,17,25])
                                  (added_sums [8,1,-5,6,7,8]) )
p4_test2 = TestCase (assertEqual "added_sums-test2"
                                  ([0,-2.5,0.5,5.3,7.3])
                                  (added_sums [0,-2.5,3,4.8,2]) )

-- P5 find_routes tests
p5_test1 = TestCase (assertEqual "find_routes-test1"
                                  (sort ["Coffee"])
                                  (sort $ find_routes "Spark" routes_test ) )

-- P6 group_sum tests
p6_test1 = TestCase (assertEqual "(group_sum-test1)"
                                  [[1,2,3],[10],[11,2,13,1]] 
                                  (group_sum [1,2,3,10,11,2,13,1] 7) )
p6_test2 = TestCase (assertEqual "(group_sum-test2)"
                                  [[],[12],[10,1,3,4],[],[],[],[],[700,4]]
                                  (group_sum [12,10,1,3,4,700,4] 10) )

-- add the test cases you created to the below list. 
tests = TestList [ TestLabel "Problem 1a- test1 " p1a_test1,
                   TestLabel "Problem 1a- test2 " p1a_test2,
                   TestLabel "Problem 1b- test1 " p1b_test1,
                   TestLabel "Problem 1b- test2 " p1b_test2,
                   TestLabel "Problem 1c- test1 " p1c_test1,
                   TestLabel "Problem 1c- test2 " p1c_test2,
                   TestLabel "Problem 2- test1 " p2_test1,
                   TestLabel "Problem 2- test2 " p2_test2,
                   TestLabel "Problem 3a- test1 " p3a_test1,
                   TestLabel "Problem 3a- test2 " p3a_test2,
                   TestLabel "Problem 3b- test1 " p3b_test1,
                   TestLabel "Problem 3b- test2 " p3b_test2,
                   TestLabel "Problem 4- test1 " p4_test1,
                   TestLabel "Problem 4- test2 " p4_test2,
                   TestLabel "Problem 5- test1 " p5_test1,
                   TestLabel "Problem 6- test1 " p6_test1,
                   TestLabel "Problem 6- test2 " p6_test2
                 ] 
                  
-- shortcut to run the tests
run = runTestTT  tests