type Birds = Int
type Polo = (Birds, Birds)

landLeft :: Int -> Polo -> Maybe Polo
landLeft n (left, right) 
    | abs (left + n - right) < 4 = Just (left + n, right)
    | otherwise = Nothing

landRight :: Int -> Polo -> Maybe Polo
landRight n (left, right) 
    | abs (left  - right - n) < 4 = Just (left, right + n)
    | otherwise = Nothing

runtime :: Maybe Polo
runtime = do
    start <- return (0, 0)
    first <- landLeft 3 start
    second <- landRight 5 first
    landLeft 3 second
