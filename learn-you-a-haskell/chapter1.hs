doubleMe x = x + x
doubleUs x y = doubleMe x + doubleMe y
doubleSmallNumber x = if x < 100 then x * 2 else x
boomBangs xs = [if x < 10 then "BOOM" else "BANGS" | x <- xs, odd x]
 xs = sum [1 | _ <- xs]