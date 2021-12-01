from multiprocessing import Process


def func():
    for i in range(10000):
        print('sub-process', i)


if __name__ == '__main__':
    p = Process(target=func)
    p.start()
    for i in range(10000):
        print('main-process', i)
