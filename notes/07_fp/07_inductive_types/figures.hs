type Point =  (Float,Float)

data Figure = Circle Point Float | 
              Square Point Float |
              Rectangle Point Float Float |
              Triangle  Point Point Point |
              Group [Figure]

girl ::   Figure =   Group [Triangle (200,200) (100,300) (300,300),
                            Circle (200,100) 50,
                            Rectangle (100,320) 20 100,
                            Rectangle (280,320) 20 100]

boy ::   Figure  =   Group [Rectangle (400,170)  100 140, 
                           Circle (450,100) 50,
                            Rectangle (400,320) 20 100,
                            Rectangle (480,320) 20 100]

picture :: Figure = Group [girl, boy, Rectangle (50,30) 500 500]                    


distance :: Point -> Point -> Float
distance (x1,y1) (x2,y2) = sqrt ((x1-x2)^2 + (y1-y2)^2)

perimeter :: Figure -> Float
perimeter (Circle _ r) = 2 * pi * r
perimeter (Square _ s) = 4 * s
perimeter (Rectangle _ w h) = 2 * (w + h)
perimeter (Triangle a b c) = sum $ zipWith distance [a,b,c] [b,c,a]
perimeter (Group figs) = sum $ map perimeter figs


svg :: Figure -> String
svg (Circle (x,y) r) = "<circle cx=\"" ++ show x ++ "\" cy=\"" ++ show y ++ "\" r=\"" ++ show r ++ "\" fill=\"none\" stroke=\"black\"/>\n"
svg (Square (x,y) s) = "<rect x=\"" ++ show x ++ "\" y=\"" ++ show y ++ "\" width=\"" ++ show s ++ "\" height=\"" ++ show s ++ "\" fill=\"none\" stroke=\"black\"/>\n"
svg (Rectangle (x,y) w h) = "<rect x=\"" ++ show x ++ "\" y=\"" ++ show y ++ "\" width=\"" ++ show w ++ "\" height=\"" ++ show h ++ "\" fill=\"none\" stroke=\"black\"/>\n"
svg (Triangle (xa,ya) (xb,yb) (xc,yc)) = "<polygon points=\"" ++ show xa ++ "," ++ show ya ++ " " ++ show xb ++ "," ++ show yb ++ " " ++ show xc ++ "," ++ show yc ++ " " ++ "\" fill=\"none\" stroke=\"black\"/>\n"
svg (Group figs) = concatMap svg figs

allsvg :: Figure -> String
allsvg fig = "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n" ++  svg fig ++ "</svg>"

