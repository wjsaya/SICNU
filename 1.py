import multiprocessing
import random

def t(i, j):
    print(i)

if __name__ == "__main__":
    queue = multiprocessing.Queue()
    processlist = []
    for i in range(1, 10):
        process = multiprocessing.Process(target=t, args=(i, i))
        process.start()
        processlist.append(process)
    for p in processlist:
        p.join()

