from threading import Thread

# common solution 1

def func(arg):
    for i in range(1000):
        print(arg, i)


if __name__ == '__main__':
    t1 = Thread(target=func, args=['cat'])     # the arguments must be iterable
    t1.start()

    t2 = Thread(target=func, args=('dog',))
    t2.start()

    for i in range(1000):
        print('main', i)


# common solution 2

# class MyThread(Thread):
#     def run(self):
#         for i in range (1000):
#             print('sub-thread', i)
#
# t = MyThread()
# t.start()
# for i in range(1000):
#     print('main-thread', i)

