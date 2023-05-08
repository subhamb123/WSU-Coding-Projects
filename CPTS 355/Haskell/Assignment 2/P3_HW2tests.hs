module P3_HW2tests
    where

import Test.HUnit
import Data.Char
import Data.List (sort)
import HW2

---------------------------------------------------------
{-Test input for find_routes -}
routes = [("Lentil",["Chinook", "Orchard", "Valley", "Emerald","Providence", "Stadium", "Main", "Arbor", "Sunnyside", "Fountain", "Crestview", "Wheatland", "Walmart", "Bishop", "Derby", "Dilke"]), 
   ("Wheat",["Chinook", "Orchard", "Valley", "Maple","Aspen", "TerreView", "Clay", "Dismores", "Martin", "Bishop", "Walmart", "PorchLight", "Campus"]), 
   ("Silver",["TransferStation", "PorchLight", "Stadium", "Bishop","Walmart", "Outlet", "RockeyWay","Main"]),
   ("Blue",["TransferStation", "State", "Larry", "TerreView","Grand", "TacoBell", "Chinook", "Library"]),
   ("Gray",["TransferStation", "Wawawai", "Main", "Sunnyside","Crestview", "CityHall", "Stadium", "Colorado"]),
   ("Coffee",["TransferStation", "Grand", "Main", "Visitor","Stadium", "Spark", "CUB"])] 

-----------------------------------------------------------     

-- find_routes tests
p3_test1 = TestCase (assertEqual "find_routes-test1"
                                  (sort ["Lentil","Wheat","Silver"])
                                  (sort $ find_routes "Walmart" routes ) )
p3_test2 = TestCase (assertEqual "find_routes-test2"
                                  ([])
                                  (sort $ find_routes "Rosauers" routes ) )
p3_test3 = TestCase (assertEqual "find_routes-test3"
                                  (sort ["Lentil","Silver","Gray","Coffee"])
                                  (sort $ find_routes "Main" routes ) )

tests = TestList [ TestLabel "Problem 3  - test1 " p3_test1,
                   TestLabel "Problem 3  - test2 " p3_test2,  
                   TestLabel "Problem 3  - test3 " p3_test3
                 ] 
                  

-- shortcut to run the tests
run = runTestTT  tests