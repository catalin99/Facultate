module Geometry  
( cubeVolume  
, cubeArea  
, cuboidArea  
, cuboidVolume
) where  

cubeVolume :: Float -> Float  
cubeVolume side = cuboidVolume side side side  
  
cubeArea :: Float -> Float  
cubeArea side = cuboidArea side side side

cuboidVolume :: Float -> Float -> Float -> Float  
cuboidVolume a b c = rectangleArea a b * c  
  
cuboidArea :: Float -> Float -> Float -> Float  
cuboidArea a b c = rectangleArea a b * 2 + rectangleArea a c * 2 + rectangleArea c b * 2  
  
rectangleArea :: Float -> Float -> Float  
rectangleArea a b = a * b