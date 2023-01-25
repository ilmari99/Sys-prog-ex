import threading
import time
import random

def a():
    global L
    values = [0,0,0,1]
    for _ in range(2):
        for i,_ in enumerate(L):
            time.sleep(random.random()/100)
            L[i] = values[i]
        

def b():
    global L
    values = [0,0,1,0]
    for _ in range(2):
        for i,_ in enumerate(L):
            time.sleep(random.random()/100)
            L[i] = values[i]

def main():
    th1 = threading.Thread(target=a)
    th2 = threading.Thread(target=b)
    th1.start()
    th2.start()
    th1.join()
    th2.join()
    print(L)


# L voi olla normaalisti 1 tai 2, mutta joissain suoritusjarjestyksissa ja viiveilla L saa arvon 3 tai 0.
# PS. Threadeissa tulee olla tarpeeksi suurta vaihtelua suoritusnopeuksissa, jotta L saisi arvon 3 tai 0 ([0,0,1,1] tai [0,0,0,0]). Taman takia lisatty satunnainen time.sleep()
if __name__ == "__main__":
    for i in range(1000000):
        L = [0,0,0,0]
        main()
        assert L[2] != L[3], "Now L equals 3 or 0 in binary, L = {}".format(L)