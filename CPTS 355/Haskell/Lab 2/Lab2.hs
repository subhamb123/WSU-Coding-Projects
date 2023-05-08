-- CptS 355 - Lab 2 (Haskell) - Spring 2023
-- Name: Subham
-- Collaborated with: 

module Lab2
     where


-- 1
{- (a) merge2 -}
merge2 x [] = x
merge2 [] y = y
merge2 (x:xs) (y:ys) = x:y:(merge2 xs ys)
                         
{- (b) merge2Tail -}
merge2Tail x y = merge2Tail x y []
     where
          merge2Tail x [] buf = buf ++ x
          merge2Tail [] y buf = buf ++ y
          merge2Tail (x:xs) (y:ys) buf = merge2Tail xs ys (buf ++ [x] ++ [y])

{- (c) mergeN -}


-- 2 (works)
{- (a) count -}
count v xs = length $ filter (\x -> x == v) xs

{- (b) histogram  -}
histogram xs = elimDup (map (\x -> (x, count x xs)) xs)
     where
          elimDup xs = foldr helper [] xs
          helper x base | (x `elem` base) = base
                        | otherwise = x:base

-- 3                
{- (a) concatAll -}
concatAll lst = concat (map concat lst)
     where
          concat xs = foldr (:) [] xs

{- (b) concat2Either -}               
data AnEither  = AString String | AnInt Int
                deriving (Show, Read, Eq)

concat2Either lst = concat (map concat lst)
     where
          concat xs = foldr maybe_concat (AString "") xs

          maybe_concat (AString x) (AString y) = AString ""
          maybe_concat (AString "") (AString "") = AString ""

-- 4      
{-  concat2Str -}               


data Op = Add | Sub | Mul | Pow
          deriving (Show, Read, Eq)

evaluate:: Op -> Int -> Int -> Int
evaluate Add x y =  x+y
evaluate Sub   x y =  x-y
evaluate Mul x y =  x*y
evaluate Pow x y = x^y

data ExprTree a = ELEAF a | ENODE Op (ExprTree a) (ExprTree a)
                  deriving (Show, Read, Eq)

-- 5 (works)
{- evaluateTree -}
evaluateTree (ELEAF v) = v
evaluateTree (ENODE Add left right) = (evaluateTree left) + (evaluateTree right)
evaluateTree (ENODE Sub left right) = (evaluateTree left) - (evaluateTree right)
evaluateTree (ENODE Mul left right) = (evaluateTree left) * (evaluateTree right)
evaluateTree (ENODE Pow left right) = (evaluateTree left) ^ (evaluateTree right)

-- 6 (works)
{- printInfix -}
printInfix (ELEAF v) = show v
printInfix (ENODE Add left right) = "(" ++ (printInfix left) ++ " `Add` " ++ (printInfix right) ++ ")"
printInfix (ENODE Sub left right) = "(" ++ (printInfix left) ++ " `Sub` " ++ (printInfix right) ++ ")"
printInfix (ENODE Mul left right) = "(" ++ (printInfix left) ++ " `Mul` " ++ (printInfix right) ++ ")"
printInfix (ENODE Pow left right) = "(" ++ (printInfix left) ++ " `Pow` " ++ (printInfix right) ++ ")"

--7 (works)
{- createRTree -}
data ResultTree a  = RLEAF a | RNODE a (ResultTree a) (ResultTree a)
                     deriving (Show, Read, Eq)

createRTree (ELEAF v) = RLEAF v
createRTree (ENODE Add left right) = RNODE value (createRTree left) (createRTree right)
     where value = (evaluateTree left) + (evaluateTree right)
createRTree (ENODE Sub left right) = RNODE value (createRTree left) (createRTree right)
     where value = (evaluateTree left) - (evaluateTree right)
createRTree (ENODE Mul left right) = RNODE value (createRTree left) (createRTree right)
     where value = (evaluateTree left) * (evaluateTree right)
createRTree (ENODE Pow left right) = RNODE value (createRTree left) (createRTree right)
     where value = (evaluateTree left) ^ (evaluateTree right)