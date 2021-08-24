import re
import requests
import asyncio
import aiohttp
import aiofiles
import os


def get_m3u8(url):
    res = requests.get(url)
    expression = re.compile(r"url: '(?P<url>.*?)',", re.S)
    m3u8_url = expression.search(res.text).group('url')
    m3u8 = requests.get(m3u8_url)
    with open('.\\video.m3u8', 'wb') as fp:
        fp.write(m3u8.content)
    print('finished downloading m3u8 file.')


async def download_ts(url, file_name, session):
    async with session.get(url) as res:
        async with aiofiles.open(f'.\\video\\{file_name}', 'wb') as f:
            await f.write(await res.content.read())
    print(f'{file_name} done')


async def aio_download():
    tasks = []
    i = 1
    async with aiohttp.ClientSession() as session:
        async with aiofiles.open('.\\video.m3u8', 'r', encoding='utf-8') as fp:
            async for line in fp:
                if line.startswith('#'):
                    continue
                line = line.strip()
                ts_url = line
                tasks.append(asyncio.create_task(download_ts(ts_url, f'{i}.ts', session)))
                i += 1
            await asyncio.wait(tasks)


def main(url):
    get_m3u8(url)
    asyncio.run(aio_download())


if __name__ == '__main__':
    url = 'https://91kanju.com/vod-play/54812-1-1.html'
    main(url)
    os.system('cd /d D:\\Projects\\Learn\\PythonCrawler\\Chapter4 - multithreading, multiprocessing, coroutines\\video && copy /b *.ts movie.mp4')
