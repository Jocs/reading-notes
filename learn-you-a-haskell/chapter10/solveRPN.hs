solveRPN :: String -> Double
solveRPN = head . foldl calculate [] . words
    where calculate (x:y:rest) "+" =  (x + y) : rest
          calculate (x:y:rest) "-" = (y - x) : rest
          calculate (x:y:rest) "*" = (x * y) : rest
          calculate (x:y:rest) "/" = (y / x) : rest
          calculate xs item = read item : xs

