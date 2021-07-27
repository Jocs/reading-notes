{--main = do 
    line <- fmap reverse getLine
    putStrLn (line ++ " is reverse of the original string!")--}

import Data.Char
import Data.List

main = do
    line <- fmap (intersperse '-' . reverse . map toUpper) getLine
    putStrLn (line ++ " is the process string!")