-- CptS 355 - Spring 2023 -- Homework2 - Haskell
-- Name: Subham Behera
-- Collaborators: 

module HW2
     where

{- P1 - remove_every, remove_every_tail  -}

-- (a) remove_every – 7%
-- Fixed base case by putting it as one of the helper patterns. Added missing arguments on lines 15 and 16.
remove_every n lst = remove_helper n lst n 
     where
          remove_helper n [] k = [] 
          remove_helper 0 (x:xs) k = (remove_helper k xs k) 
          remove_helper n (x:xs) k = x:(remove_helper (n-1) xs k) 

-- (b) remove_every_tail –  10%
remove_every_tail n lst = remove_every_tail_helper n lst n []
     where
          remove_every_tail_helper n [] k buf = buf
          remove_every_tail_helper 0 (x:xs) k buf = (remove_every_tail_helper k xs k buf) 
          remove_every_tail_helper n (x:xs) k buf = (remove_every_tail_helper (n-1) xs k (buf ++ [x])) 

------------------------------------------------------
{- P2  get_outof_range and count_outof_range  -}

-- (a) get_outof_range – 6%
get_outof_range v1 v2 xs = filter range xs
     where
          range x = if (x < v1 || x > v2) then True else False

-- (b) count_outof_range – 10%
count_outof_range v1 v2 xs = foldr (+) 0 (map (length) (map (filter range) xs))
     where
          range x = if (x < v1 || x > v2) then True else False

------------------------------------------------------
{- P3  find_routes - 10% -}
find_routes dest xs = map fst (filter route xs)
     where
          route (x,y) = if (elem dest y) then True else False

------------------------------------------------------
{- P4  add_lengths and add_nested_lengths -}
data LengthUnit =  INCH  Int | FOOT  Int | YARD  Int 
                   deriving (Show, Read, Eq)

-- (a) add_lengths - 6%
add_lengths (INCH x) (INCH y) = INCH (x+y)
add_lengths (INCH x) (FOOT y) = INCH (x+12*y)
add_lengths (INCH x) (YARD y) = INCH (x+36*y)
add_lengths (FOOT x) (FOOT y) = INCH (12*x+12*y)
add_lengths (FOOT x) (INCH y) = INCH (12*x+y)
add_lengths (FOOT x) (YARD y) = INCH (12*x+36*y)
add_lengths (YARD x) (YARD y) = INCH (36*x+36*y)
add_lengths (YARD x) (INCH y) = INCH (36*x+y)
add_lengths (YARD x) (FOOT y) = INCH (36*x+12*y)

-- (b) add_nested_lengths - 10%
add_nested_lengths lst = foldr add_lengths (INCH 0) (map help lst)
     where
          help x = foldr add_lengths (INCH 0) x

------------------------------------------------------
{- P5 sum_tree and create_sumtree -}
data Tree a = NULL | LEAF a | NODE a  (Tree a)  (Tree a)  
              deriving (Show, Read, Eq) 

-- (a) sum_tree - 8%
sum_tree NULL = 0
sum_tree (LEAF a) = a
sum_tree (NODE a t1 t2) = a + (sum_tree t1) + (sum_tree t2)

-- (b) create_sumtree - 10%
create_sumtree NULL = NULL
create_sumtree (LEAF x) = LEAF x
create_sumtree (NODE a t1 t2) = NODE (a+(sum_tree t1)+(sum_tree t2)) (create_sumtree t1) (create_sumtree t2)

------------------------------------------------------
{- P6 list_tree - 16% -}
data ListTree a = LEAFs [a] | NODEs [(ListTree a)] 
                  deriving (Show, Read, Eq)

list_tree f base (NODEs []) = base
list_tree f base (NODEs a) = foldr f base (map (list_tree f base) a)
list_tree f base (LEAFs a) = foldr f base a

-- Tree examples - 4%
-- INCLUDE YOUR TREE EXAMPLES HERE
tree1 = (NODE 3.5 (NODE 7.12 (LEAF (-87)) (NODE 10 (LEAF 4) (LEAF 1))) (NODE (-10) (NODE 3 NULL (NODE 10 NULL (LEAF (-3.2)))) NULL))
tree2 = (NODE (-45.34) (NODE 90 (LEAF (-7)) (NODE 10 (NODE 10 NULL NULL) (NODE 10 (LEAF 7) (LEAF 1)))) (LEAF 0.2))

sum1 = sum_tree tree1
sum2 = sum_tree tree2
create1 = create_sumtree tree1
create2 = create_sumtree tree2

-- Assignment rules 3%
