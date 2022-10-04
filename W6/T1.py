import threading

def a():
    global x
    for i in range(1000000):
        x = 1
        x = y + 1

def b():
    global y
    for i in range(1000000):
        y = 2
        y = y*2

def main():
    th1 = threading.Thread(target=a)
    th2 = threading.Thread(target=b)
    th1.start()
    th2.start()
    th1.join()
    th2.join()
    print(x,y)

x = 1
y = 2
if __name__ == "__main__":
    main()
    # Globaali muuttuja x voi saada arvot 5 tai 3. Tama riippuu siita, onko viimeisessa a loopissa y==2 vai y==2*2