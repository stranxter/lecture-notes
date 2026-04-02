
data Season = Spring | Summer | Autumn | Winter
    deriving (Show, Eq, Ord, Enum)

data Point = Point Double Double
    deriving (Show, Eq)


getX (Point x _) = x
getY (Point _ y) = y

data Shape = Circle Double | Rectangle Double Double | Group [Shape]
    deriving (Show, Eq)

fig = Group [
               Group [Circle 1, Rectangle 2 4],
               Group [Circle 1.5, Rectangle 2 2]      
            ]

area :: Shape -> Double
area (Circle r) = 3.14*r*r
area (Rectangle a b) = a * b
area (Group fs) = sum $ map area fs

figures = [Circle 1, Rectangle 2 3, Circle 2, Rectangle 3 4]

--data Student = Student String Int [(String,Int)]

{--
data Mark = Mark {subj::String, mark::Double}
    deriving (Show, Eq)
data Student = Student {name::String, fn::Int, grades::[Mark]}
    deriving (Show, Eq)


students :: [Student] =  [Student {name="Ivan", fn = 42424, grades = [Mark "fp" 6, Mark "oop" 6]},
                           Student {name="Maria", fn = 757575, grades = [Mark "sport" 6]}];

--}

data Employee = Employee {name::String, salary::Double, manages::[Employee]}
    deriving (Show)

boss = Employee {name="Ivan Petrov",
                 salary = 1000,
                 manages=[
                            Employee {name="Maria Petrova",
                                      salary=1050,
                                      manages=[]},
                            Employee {name="Petyr Petrov",
                                      salary=800,
                                      manages=[
                                                  Employee {name="Bai Ivan",
                                                            salary=500,
                                                            manages=[]},
                                                   Employee {name="Iva",
                                                            salary=600,
                                                            manages=[]}
                                              ]}
                         ]}                                      

payroll :: Employee->Double
payroll (Employee _ salary subs) = salary + sum $ (map payroll subs)


