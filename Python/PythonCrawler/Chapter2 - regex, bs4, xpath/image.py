import requests


headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) '
                  'Chrome/88.0.4324.190 Safari/537.36 '
}
url = 'https://pic.qiushibaike.com/system/pictures/12449/124497118/medium/SO15LW0NEXHONN1L.jpg'

img_data = requests.get(url).content
with open('.\\qiutu.png', 'wb') as fp:
    fp.write(img_data)
print('done')