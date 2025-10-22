import Control.Concurrent
import Control.Concurrent.Async

action1 :: IO Int
action1 = do
    threadDelay 500000 -- just to make it interesting
    return 5

action2 :: IO Int
action2 = do
    threadDelay 1000000
    return 10

main :: IO ()
main = do
    (a,b) <- concurrently action1 action2
    print (a+b)
    a1 <- async action1
    print "Do something else"
    c <- wait a1
    print c