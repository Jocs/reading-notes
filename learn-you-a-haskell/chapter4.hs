maximum' :: (Ord a) => [a] -> a
maximum' ls 
    | length ls == 0 = error "Prelude.maximum: empty list"
    | length ls == 1 = head ls
    | (head ls) >= (maximum (tail ls)) = head ls
    | otherwise = maximum (tail ls)

replicate' :: Int -> a -> [a]
replicate' n x
    | n <= 0 = []
    | otherwise = x:replicate' (n -1) x

zip' :: [a] -> [b] -> [(a, b)]
zip' _ [] = []
zip' [] _ = []
zip' (x:xs) (y:ys) = (x, y):zip' xs ys

elem' :: (Eq a) => a -> [a] -> Bool
elem' a [] = False
elem' a (x:xs)
    | a == x = True
    | otherwise = elem' a xs

reverse' :: [a] -> [a]
reverse' [] = []
reverse' (x:xs) = reverse' xs ++ [x]

repeat' :: a -> [a]
repeat' x = x:repeat' x

quickSort :: (Ord a) => [a] -> [a]
quickSort [] = []
quickSort (x:xs) =
    let lager = [a | a<- xs, a > x]
        smallOrEqual = [a | a <- xs, a <= x]
    in quickSort smallOrEqual ++ [x] ++ quickSort lager

take' :: (Num i, Ord i) => i -> [a] -> [a]
take' n _ 
    | n <= 0 = []
take' n [] = []
take' n (x:xs) = x : take' (n - 1) xs



