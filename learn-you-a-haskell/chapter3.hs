lucky :: Int -> String
lucky 7 = "LUCKY NUMBER SEVEN"
lucky x = "Sorry! You miss the lucky number!"

factorial :: Int -> Int
factorial 0 = 1
factorial n = n * factorial(n - 1)

addVectors :: (Double, Double) -> (Double, Double) -> (Double, Double)
addVectors (x1, y1) (x2, y2) = (x1 + x2, y1 + y2)

first :: (a, b, c) -> a
first (x, _, _) = x

second :: (a, b, c) -> b
second (_, y, _) = y

third :: (a, b, c) -> c
third (_, _, z) = z

getSum xs = [a + b | (a, b) <- xs]

head' :: [a] -> a
head' [] = error "Can't call head on an empty list, dummy!"
head' (x:_) = x

tell :: (Show a) => [a] -> String
tell [] = "This list is empty"
tell (x:[]) = "This list has only one element " ++ show x
tell (x:y:[]) = "This list has two elements " ++ show x ++ " and " ++ show y
tell (x:y:_) = "THIS list is long the first two elements are " ++ show x ++ " and " ++ show y

bmiTell :: Double -> String
bmiTell bmi 
    | bmi <= 18.5 = "You are underweight, you emo, you"
    | bmi <= 25 = "你的体重正常，我怎么觉得你有点丑"
    | bmi <= 30 = "你有点胖，但是很可爱"
    | otherwise = "你的胖超乎你的想象"

max' :: (Ord a) => a -> a -> a
max' a b
    | a <= b = b
    | otherwise = a

badGreeting :: String
badGreeting = "Oh! Pfft, It's you"

niceGreeting :: String
niceGreeting = "Hello! So very nice you"

greet :: String -> String
greet "Juan" = niceGreeting ++ " Juan"
greet "Ran" = niceGreeting ++ " Ran"
greet name = badGreeting ++ " " ++ name

calcBmis :: [(Double, Double)] -> [Double]
calcBmis xs = [bmi w h | (w, h) <- xs]
    where bmi weight height = weight / height ^ 2

calcBmis' :: [(Double, Double)] -> [Double]
calcBmis' xs = [bmi | (w, h) <- xs, let bmi = w / h ^ 2]

describeList :: [a] -> String
describeList ls = "This list is " ++ case ls of [] -> "empty"
                                                (x:[]) -> "single list"
                                                (x:y:[]) -> "has two elements"
                                                (x:y:_) -> "longer than you think"



