import Data.List
import Data.Char
import Geometry
import qualified Geometry.Cuboid as Cuboid

wordNums :: String -> [(String, Int)]
wordNums = map (\xs -> (head xs, length xs)) . group . sort . words

isIn :: (Eq a) => [a] -> [a] -> Bool
needle `isIn` haystack = any (needle `isPrefixOf`) (tails haystack)

encode :: Int -> String -> String
encode offset message = map (\a -> chr $ ord a + offset) message

decode :: Int -> String -> String
decode shift message = encode (negate shift) message

getFirstTotaln :: Int -> Int
getFirstTotaln n = head $ filter p [1..]
    where p = (== n) . sum . map digitToInt . show 

digitSum :: Int -> Int
digitSum = sum . map digitToInt . show

findTo :: Int -> Maybe Int
findTo n = find (\i -> digitSum i == n) [1..]
