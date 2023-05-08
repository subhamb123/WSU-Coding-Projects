{-  To run the tests type "run" at the Haskell prompt.  -}

module P5_HW1tests
    where

import Test.HUnit
import Data.Char
import Data.List (sort)
import HW1

-- Problem-5 test data
-- make sure that the below list is not defined in HW1.hs
routes_test = [("Lentil",["Chinook", "Orchard", "Valley", "Emerald","Providence", "Stadium", "Main", "Arbor", "Sunnyside", "Fountain", "Crestview", "Wheatland", "Walmart", "Bishop", "Derby", "Dilke"]), 
   ("Wheat",["Chinook", "Orchard", "Valley", "Maple","Aspen", "TerreView", "Clay", "Dismores", "Martin", "Bishop", "Walmart", "PorchLight", "Campus"]), 
   ("Silver",["TransferStation", "PorchLight", "Stadium", "Bishop","Walmart", "Outlet", "RockeyWay","Main"]),
   ("Blue",["TransferStation", "State", "Larry", "TerreView","Grand", "TacoBell", "Chinook", "Library"]),
   ("Gray",["TransferStation", "Wawawai", "Main", "Sunnyside","Crestview", "CityHall", "Stadium", "Colorado"]),
   ("Coffee",["TransferStation", "Grand", "Main", "Visitor","Stadium", "Spark", "CUB"])]    


-- find_routes tests
p5_test1 = TestCase (assertEqual "find_routes-test1"
                                  (sort ["Lentil","Wheat","Silver"])
                                  (sort $ find_routes "Walmart" routes_test ) )
p5_test2 = TestCase (assertEqual "find_routes-test2"
                                  ([])
                                  (sort $ find_routes "Rosauers" routes_test ) )
p5_test3 = TestCase (assertEqual "find_routes-test3"
                                  (sort ["Lentil","Silver","Gray","Coffee"])
                                  (sort $ find_routes "Main" routes_test ) )
                                
tests = TestList [
                   TestLabel "Problem 5- test1 " p5_test1,
                   TestLabel "Problem 5- test2 " p5_test2,
                   TestLabel "Problem 5- test3 " p5_test3
                 ]

-- shortcut to run the tests
run = runTestTT  tests
