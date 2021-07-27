module Geometry.Cuboid
(
volume,
area
) where

volume :: Float -> Float -> Float -> Float
volume a b c = rectArea b c * a

rectArea :: Float -> Float -> Float
rectArea a b = a * b

area :: Float -> Float -> Float -> Float
area a b c = 2 * (a * b + b * c + a * c)