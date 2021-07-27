-- isBigGang是用来判断一个强盗团伙规模的函数，当规模大于9人，就说明这个强盗团伙是一个大的强盗团了。
isBigGang :: Int -> (Bool, String)
isBigGang x = (x > 9, "Compare to 9!")

applyLog :: (a, String) -> (a -> (b, String)) -> (b, String)
applyLog (x, log) f = (fst $ f x, log ++ (snd $ f x))