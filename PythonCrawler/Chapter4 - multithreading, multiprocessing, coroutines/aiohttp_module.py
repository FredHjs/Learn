import aiohttp, asyncio

urls = [
    'http://kr.shanghai-jiuxin.com/file/2020/1031/563337d07af599a9ea64e620729f367e.jpg',
    'http://kr.shanghai-jiuxin.com/file/2020/1031/774218be86d832f359637ab120eba52d.jpg',
    'http://kr.shanghai-jiuxin.com/file/2020/1031/6b72c57a1423c866d2b9dc10d0473f27.jpg'
]


async def aiodownload(url):
    file_name = url.rsplit('/', 1)[1]
    async with aiohttp.ClientSession() as session:
        async with session.get(url) as res:
            with open(file_name, 'wb') as fp:
                fp.write(await res.content.read())
    print(file_name, 'done')


async def main():
    tasks = []
    for url in urls:
        tasks.append(asyncio.create_task(aiodownload(url)))
    await asyncio.wait(tasks)


if __name__ == '__main__':
    asyncio.run(main())
