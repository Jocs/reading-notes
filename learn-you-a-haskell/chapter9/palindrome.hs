main = do
    contents <- getContents
    putStr $ respondPalindromes contents

respondPalindromes :: String -> String
respondPalindromes = unlines . map (\line -> if isPal line then "palindrome" else "not a palindrome") . lines

isPal :: String -> Bool
isPal xs = xs == (reverse xs)