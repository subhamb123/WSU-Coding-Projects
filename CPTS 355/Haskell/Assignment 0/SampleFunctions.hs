-- CptS 355 - Sample Functions

module SampleFunctions
     where

import Data.Char

--isNull
isNull :: [a] -> Bool
isNull [] = True
isNull (x:xs) = False

-- length of a list
length' :: [a] -> Int
length' [] = 0
length' (x:xs) = 1 + (length' xs)

-- last'
last' :: [a] -> a
last' []     = error "last': Input list is empty."
last' [x]    = x 
last' (x:xs) = (last' xs)


-- nth element
nthElement [] n = error "nthElement': The input list is too short."
nthElement (x:xs) 1 = x
nthElement (x:xs) n = (nthElement xs (n-1))

-- ======= Examples of "mapping" functions

--copyList
copyList [] = []
copyList (x:xs)  = x : (copyList xs)

-- allSquares
allSquares :: Num a => [a] -> [a]
allSquares [] = []
allSquares (x : xs) = x * x : allSquares xs
 

-- strToUpperq
strToUpper :: String -> String
strToUpper [] = []
strToUpper (chr:xs) = (toUpper chr) : (strToUpper xs)

-- ======= Examples of "filtering" functions
-- odds
odds [] = []
odds (x:xs)  | ((x `mod` 2) == 1) = x: (odds xs)
             |  otherwise = (odds xs)


-- filter if smaller than v
filterSmaller [] v = [] 
filterSmaller (x:xs) v | (x >= v) = x:(filterSmaller xs v)
                       | otherwise = (filterSmaller xs v)

--extractDigits
extractDigits :: String -> String
extractDigits [] = []
extractDigits (chr:xs) | isDigit chr = chr : extractDigits xs
                         | otherwise = extractDigits xs

-- ======= Examples of "reduction" functions
addup []     = 0
addup (x:xs) = x + (addup xs)

mul []     = 1
mul (x:xs) = x * (mul xs)

minList1 []     = maxBound
minList1 (x:xs) = x `min` (minList1 xs)

--alternative implementation for minList
minList2 []     = error "List is empty"
minList2 [x]    = x 
minList2 (x:xs) = x `min` (minList2 xs)

reverse' [] = []
reverse' (x:xs) = x `snoc` (reverse' xs)
                  where snoc x xs = xs ++ [x]

append [] list = list
append (x:xs) list = x:(append xs list)


myChar = nthElement "CptS355-Assignment1" 5

main = do print ( nthElement [1,2,3,4,5] 4)
          print ( allSquares [1,2,3,4,5] )
          print ( length [1,2,3,4,5] )
          print (myChar)