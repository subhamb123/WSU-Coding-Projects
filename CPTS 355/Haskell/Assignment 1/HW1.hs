-- CptS 355 - Spring 2023 -- Homework1 - Haskell
-- Name: Subham Behera
-- Collaborators: 

module HW1
     where

-- P1(a) count ;  6%
count value (x:xs) = count 0 value (x:xs)
     where    
          count num value [] = num
          count num value (x:xs) | (x == value) = count (num+1) value xs
                                 | otherwise = count num value xs

-- P1(b) diff ;  6%
diff x y = diff x y y
     where
          diff [] y z = []
          diff (x:xs) [] z = x:(diff xs z z)
          diff (x:xs) (y:ys) z | (x == y) = diff xs z z
                               | otherwise = diff (x:xs) ys z

-- P1(c) bag_diff ; 8%
bag_diff x y = bag_diff x y [] []
     where
          bag_diff [] y ybuf ret = ret
          bag_diff (x:xs) [] ybuf ret = bag_diff xs ybuf [] (x:ret)
          bag_diff (x:xs) (y:ys) ybuf ret | (x == y) = bag_diff xs (ybuf++ys) [] ret
                                          | otherwise = bag_diff (x:xs) ys (y:ybuf) ret

-- P2  everyN ; 10%
everyN lst n = let
     everyN [] n k = []
     everyN (x:xs) 1 k = x:(everyN xs k k)
     everyN (x:xs) n k = everyN xs (n-1) k
     in
          everyN lst n n

-- P3(a) make_sparse ; 15%
make_sparse [] = []
make_sparse ((x,y):z) = make_sparse ((x,y):z) 0 0 0
     where
          make_sparse [] temp temp2 size = []
          make_sparse ((x,y):z) temp temp2 size | ((x-temp2) > 0 && (x+temp) > size) = 0:(make_sparse (((x-1),y):z) (temp+1) temp2 (size+1))
                                                | ((x-temp2) > 0) = (make_sparse (((x-1),y):z) (temp+1) temp2 size)
                                                | otherwise = y:(make_sparse z 0 temp (size+1))              

-- P3(b) compress ; 15%
compress [] = []
compress lst = compress lst 0
     where
          compress [] num = []
          compress (x:xs) num | (x == 0) = compress xs (num+1)
                              | otherwise = (num,x):(compress xs (num+1))

-- P4 added_sums ; 8%
added_sums lst = added_sums lst 0
     where
          added_sums [] prev = []
          added_sums (x:xs) prev = (x+prev):(added_sums xs (x+prev))

-- P5 find_routes ; 8%
find_routes dest [] = []
find_routes dest ((x,[]):xs) = find_routes dest xs
find_routes dest ((x,(y:ys)):xs) | (y == dest) = x:(find_routes dest xs)
                                 | otherwise = (find_routes dest ((x,ys):xs))

-- P6 group_sum ; 15% 
group_sum lst n = group_sum lst n 0 0 []
     where
          snoc x xs = xs ++ [x]
          group_sum [] n sum k sublst = [sublst]
          group_sum (x:xs) n sum k sublst | ((sum+x) <= (n*(2^k))) = group_sum xs n (sum+x) k (x `snoc` sublst)
                                          | otherwise = sublst : (group_sum (x:xs) n 0 (k+1) [])

-- Assignment rules ; 3%
-- Your own tests; please add your tests to the HW1Tests.hs file ; 6%



