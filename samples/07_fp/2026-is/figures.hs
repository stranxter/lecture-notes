

type Point = (Int,Int)

data Shape = Circle {center :: Point, radius :: Int} | 
             Rect { topright :: Point, width :: Int, height :: Int} |
             Triangle {pa :: Point, pb :: Point, pc :: Point}


fig = [Circle (200,100) 50,
       Rect (100,320) 20 100,
       Rect (250,320) 20 100,
       Triangle (200,200) (100,300) (300,300)]


shapeToTag :: Shape -> String

shapeToTag (Circle (x,y) r) = "<circle cx=\"" ++ show x ++ "\"" ++ 
                                      " cy=\"" ++ show y ++ "\"" ++
                                      " r=\"" ++ show r ++ "\" fill=\"none\" stroke=\"black\"/>"

shapeToTag (Rect (x,y) w h) = "<rect  x=\"" ++ show x ++ "\"" ++ 
                                      " y=\"" ++ show y ++ "\"" ++
                                      " width=\"" ++ show w ++ "\"" ++
                                      " height=\"" ++ show h ++ "\" fill=\"none\" stroke=\"black\"/>"

shapeToTag (Triangle (x1,y1) (x2,y2) (x3,y3))
                              = "<polygon points=\"" ++ show x1 ++ "," ++ show y1 ++ " " ++
                                                show x2 ++ "," ++ show y2 ++ " " ++ 
                                                show x3 ++ "," ++ show y3 ++ "\"" ++
                                " fill=\"none\" stroke=\"black\"/>" 

saveToSvg :: [Shape] -> String -> IO ()
saveToSvg shapes file = do
    let tags = concat $ map ((++"\n").shapeToTag) shapes
    writeFile file ("<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n" ++ tags ++ "\n</svg>")