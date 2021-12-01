
# 'http://dushu.baidu.com/api/pc/getCatalog?data={"book_id":"4306063500"}'
# 'http://dushu.baidu.com/api/pc/getChapterContent?data={"book_id":"4306063500","cid":"4306063500|11348571","need_bookinfo":1}

import requests, asyncio, aiohttp, json, aiofiles

"""
sync: get getCatalog for the chapters' cid and names
async: get getChapterContent for all the chapter contents
"""


async def get_catalog(url):
    res = requests.get(url)
    dic = res.json()
    tasks = []
    for item in dic['data']['novel']['items']:
        title = item['title']
        cid = item['cid']
        tasks.append(asyncio.create_task(aiodownload(book_id, cid, title)))

    await asyncio.wait(tasks)


async def aiodownload(book_id, cid, title):
    data = {
        "book_id": book_id,
        "cid": book_id + '|' + cid,
        "need_bookinfo": 1
    }

    data = json.dumps(data)
    url = f'http://dushu.baidu.com/api/pc/getChapterContent?data={data}'

    async with aiohttp.ClientSession() as session:
        async with session.get(url) as res:
            dic = await res.json()
            content = dic['data']['novel']['content']
            async with aiofiles.open(f'.\\novel content\\{title}.txt', 'w', encoding='utf-8') as fp:
                await fp.write(content)



if __name__ == '__main__':
    book_id = '4306063500'
    url = 'http://dushu.baidu.com/api/pc/getCatalog?data={"book_id":"' + book_id + '"}'
    asyncio.run(get_catalog(url))
