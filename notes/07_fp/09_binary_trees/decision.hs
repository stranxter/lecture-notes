


data Node = Class String | Attr {question :: String, yes :: Node, no :: Node} 
     deriving Show

animals = Attr "Does it have feathers?"
               (Attr "Can it fly?"
                     (Class "Pidgeon")
                     (Class "Penguin"))
                (Attr "Does it have finns?"
                     (Class "Dolphin")
                     (Class "Dog"))

whichAnimal :: Node -> IO (String)
whichAnimal (Class c) = return $ "It is a " ++ c
whichAnimal (Attr q y n) = do
  putStr $ q ++ " (yes/no):"
  answer <- getLine 
  if answer == "yes" then whichAnimal y else whichAnimal n