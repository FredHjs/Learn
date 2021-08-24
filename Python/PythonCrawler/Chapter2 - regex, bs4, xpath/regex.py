import requests
import re
import os

url = 'https://www.qiushibaike.com/imgrank/page/%d/'

headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) '
                  'Chrome/88.0.4324.190 Safari/537.36 '
}

for pageNum in range(1, 3):
    format_url = format(url % pageNum)
    page_text = requests.get(format_url, headers=headers).text

    ex = '<div class="thumb">.*?<img src="(.*?)" alt.*?</div>'

    img_src_list = re.findall(ex, page_text, re.S)

    if not os.path.exists('.\\qiutuPictures'):
        os.mkdir('.\\qiutuPictures')
    for src in img_src_list:
        src = 'https:' + src
        img_data = requests.get(src, headers=headers).content

        pic_name = src.split('/')[-1]
        pic_path = '.\\qiutuPictures\\' + pic_name

        with open(pic_path, 'wb') as fp:
            fp.write(img_data)
            print(pic_name + '完事了')
