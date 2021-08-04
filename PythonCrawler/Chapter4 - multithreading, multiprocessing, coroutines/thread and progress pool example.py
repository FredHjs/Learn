from concurrent.futures import ThreadPoolExecutor, ProcessPoolExecutor


def fn(arg1, arg2):
    for i in range(1000):
        print(arg1, arg2, i)


if __name__ == '__main__':
    # create thread pool
    with ThreadPoolExecutor(50) as t:
        for i in range(100):
            t.submit(fn, arg1=f'thread{i}', arg2=f'thread{i}')
    # wait until the tasks in thread pool to be finished
    print('done.')
