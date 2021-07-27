import System.IO
import Control.Monad

main = forever $ do
    content <- getLine
    appendFile "todos.txt" (content ++ "\n")