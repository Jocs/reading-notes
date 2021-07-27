flip' :: (a -> b -> c) -> b -> a -> c
flip' f y x = f x y

compareWithHundred :: Int -> Ordering
compareWithHundred = flip' compare 100

divideByTen :: (Floating a) => a -> a
divideByTen = (/10)

-- 将前缀函数转化为中缀函数只需要加反引号
isUpperCase :: Char -> Bool
isUpperCase = (`elem` ['A'..'Z'])

applyTwice :: (a -> a) -> a -> a
applyTwice f x = f $ f x

zipWith' :: (a -> b -> c) -> [a] -> [b] -> [c]
zipWith' _ [] _ = []
zipWith' _ _ [] = []
zipWith' f (x:xs) (y:ys) = f x y : zipWith' f xs ys

map' :: (a -> b) -> [a] -> [b]
map' _ [] = []
map' f (x:xs) = f x : map' f xs

filter' :: (a -> Bool) -> [a] -> [a]
filter' _ [] = []
filter' p (x:xs)
    | p x = x : filter' p xs
    | otherwise = filter' p xs

quickSort :: (Ord a) => [a] -> [a] 
quickSort [] = []
quickSort (x:xs) = 
    let smallerOrEqual = filter (<= x) xs
    	larger = filter (> x) xs
    in quickSort smallerOrEqual ++ [x] ++ quickSort larger

largestDivisible :: Integer
largestDivisible = head $ filter p [100000, 99999..]
    where p x = x `mod` 3829 == 0

-- 克拉此序列
chain :: Integer -> [Integer]
chain 1 = [1]
chain n
    | even n = n:chain (n `div` 2)
    | odd n = n:chain (n * 3 + 1)

numberLongChain :: Int
numberLongChain = length $ filter (\xs -> length xs > 15) $ map chain [1..100]

sum' :: (Num a) => [a] -> a
sum' xs = foldl (\acc x -> acc + x) 0 xs

sum'' :: (Num a) => [a] -> a
sum'' xs = foldr (\x acc -> x + acc) 0 xs

sum''' :: (Num a) => [a] -> a
sum''' = foldl (+) 0

map'' :: (a -> b) -> [a] -> [b]
map'' f xs = foldr (\x acc -> f x:acc) [] xs

elem' :: (Eq a) => a -> [a] -> Bool
elem' e xs = foldl (\acc x -> if x == e then True else acc) False xs

reverse' :: [a] -> [a]
reverse' = foldl (\acc x -> x:acc) []

product' :: (Num a) => [a] -> a
product' = foldl (\acc x -> x * acc) 1

filter'' :: (a -> Bool) -> [a] -> [a]
filter'' p = foldr (\x acc -> if p x then x:acc else acc) []








