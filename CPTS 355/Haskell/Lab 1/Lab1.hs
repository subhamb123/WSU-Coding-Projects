-- CptS 355 - Lab 1 (Haskell) - Spring 2023
-- Name: Subham Behera


module Lab1
     where


-- 1.insert 
insert 0 item x = item : x
insert n item [] = []
insert n item (x:xs) = x : (insert (n-1) item xs)

-- 2. insertEvery
insertEvery n item lst = let
     insertHelper n item [] k | (n == 0) = [item]
                              | otherwise = []
     insertHelper 0 item (x:xs) k = x:item:(insertHelper k item xs k)
     insertHelper n item (x:xs) k = x:(insertHelper (n-1) item xs k)
     in
          insertHelper n item lst n

-- 3. getSales
getSales day [] = 0
getSales day ((x,y):xs) = if x == day then y + (getSales day xs) else (getSales day xs)
                                                  
--  4. sumSales
sumSales store day [] = 0
sumSales store day ((x,y):xs) | (store == x) = (getSales day y) + (sumSales store day xs)
                              | otherwise = (sumSales store day xs)

-- 5. split
split c lst = shelper c lst []
     where 
          shelper c [] buf | (buf == []) = []
                           | otherwise = (reverse buf):[]
          shelper c (x:xs) buf | (c == x) = (reverse buf):(shelper c xs [])
                               | otherwise = shelper c xs (x:buf)

-- 6. nSplit
nSplit c n lst = nSplitHelper c n lst []
     where 
          nSplitHelper c n [] buf | (buf == []) = []
                                  | otherwise = (reverse buf):[]
          nSplitHelper c n (x:xs) buf | (c == x) && (n > 0) = (reverse buf):(nSplitHelper c (n-1) xs [])
                                      | (c /= x) && (n > 0) = (nSplitHelper c n xs (x:buf))
                                      | otherwise = (x:xs):[]