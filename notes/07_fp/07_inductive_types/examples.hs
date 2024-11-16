import Data.Time.Calendar
import Data.Time.Clock.POSIX

epoch :: IO Int
epoch = do
    ptime <- getPOSIXTime
    return $ round ptime

data Task = SimpleTask {descr :: String, start :: Day, duration :: Integer} | 
            ComplexTask {descr:: String, subtasks :: [Task]}
    deriving (Show,Eq,Read)

learnFP = ComplexTask "Take a course"
           [ComplexTask "Study"
                [SimpleTask "Read Textbook" (read "2025-02-01") 20,
                 SimpleTask "Do homeworks" (read "2025-02-10") 20],
            SimpleTask "Take Exam" (read "2025-03-01") 1]

completed :: Task -> Day -> Bool
completed (SimpleTask _ start duration) today = addDays duration start < today
completed (ComplexTask _ ts) today = all (\t -> completed t today) ts
