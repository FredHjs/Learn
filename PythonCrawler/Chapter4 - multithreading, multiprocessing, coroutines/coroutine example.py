import asyncio
import time


async def func1():
    print('hello, my name is jacky')
    await asyncio.sleep(3)      # the operation after await must be an async operation. that's why we don't use time.sleep()
    print('hello, my name is jacky')


async def func2():
    print('hello, my name is jason')
    await asyncio.sleep(2)
    print('hello, my name is jason')


async def func3():
    print('hello, my name is tom')
    await asyncio.sleep(4)
    print('hello, my name is tom')


async def main():
    f1 = asyncio.create_task(func1())       # have to wrap func as task after 3.10
    f2 = asyncio.create_task(func2())
    f3 = asyncio.create_task(func3())
    tasks = [f1, f2, f3]
    await asyncio.wait(tasks)


if __name__ == '__main__':
    t1 = time.time()
    asyncio.run(main())
    t2 = time.time()
    print(t2-t1)        # if the three funcs are ran in a row, we need at least 9 seconds

    # we can also do the following, but it's not recommended run all the coroutines on the main thread
    # f1 = func1()
    # f2 = func2()
    # f3 = func3()
    # tasks = [f1, f2, f3]
    # t1 = time.time()
    # asyncio.run(asyncio.wait(tasks))
    # t2 = time.time()
    # print(t2-t1)
