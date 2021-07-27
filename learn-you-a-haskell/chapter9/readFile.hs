import System.IO

main = do
    handle <- openFile "pal.txt" ReadMode
    contents <- hGetContents handle
    putStr contents
    hClose handle