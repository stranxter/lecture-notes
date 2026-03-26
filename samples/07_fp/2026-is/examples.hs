students :: [(String,Int,[(String,Double)])] 
         =   [("Ivan",42424,[("fp",6),("oop",6),("dis",5)]),
              ("Maria",757575,[("fp",6),("oop",5),("dis",6)]),
              ("Petyr",2424,[("fp",6),("fp",5),("oop",5),("oop",6)])]


--да се намери средния успех по даден предмет
--avggrade subj ss

avggrade subj ss = let grades = getGrades ss
                       onlys = getonlyforsubj grades subj
                       marks = justmarks onlys
                       in avgl marks
           
--да извадим само оценките от списъска
--getGrades s -> списък само с оценките [("fp",6),("oop",6),("dis",5), ("fp",6),("oop",5),("dis",6)]

getGrades ss = concat (map (\(_,_,g)->g) ss)

--филтрираме само оценките по даден предмет
--getonlyforsubj grades subject -> [("fp",6),("fp",5)]

getonlyforsubj gs tsubj =
     filter (\(subj,g)->subj==tsubj) gs

--махаме предмета, оставяме само оценките
--justmarks grades -> [6,5]

justmarks gs = map (\(_,m)->m) gs

--намираме средно аритметично на списък от числа
--average l -> 5.5

avgl l = (sum l) / fromIntegral (length l)

--да се намери списък с имена на студенти, които нямат нито една оценка по даден предмет
--needtoexam studs subj

subjectforstudent (_,_,gs) = map fst gs

needtoexam ss subj = map (\(f,_,_)->f) $ filter (\stud->not $ elem subj (subjectforstudent stud)) ss