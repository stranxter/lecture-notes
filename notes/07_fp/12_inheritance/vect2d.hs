newtype Vect2D a = Vect2D (a, a) deriving (Show, Eq)

instance Num a => Num (Vect2D a) where
    (Vect2D (x1, y1)) + (Vect2D (x2, y2)) = Vect2D (x1 + x2, y1 + y2)
    (Vect2D (x1, y1)) - (Vect2D (x2, y2)) = Vect2D (x1 - x2, y1 - y2)
    (Vect2D (x1, y1)) * (Vect2D (x2, y2)) = Vect2D (x1 * x2, y1 * y2)
    abs (Vect2D (x, y)) = Vect2D (abs x, abs y)
    signum (Vect2D (x, y)) = Vect2D (signum x, signum y)
    fromInteger i = Vect2D (fromInteger i, fromInteger i)

