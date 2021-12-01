# 网页采集器

import requests

url = "https://www.sogou.com/web"

keyword = input('enter the search keyword:')
headers = {
    'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,'
              'application/signed-exchange;v=b3;q=0.9',
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) '
                  'Chrome/88.0.4324.190 Safari/537.36 '
}
param = {
    'query': keyword
}

response = requests.get(url=url, params=param, headers=headers)

text = response.text
filename = keyword + '.html'

with open(filename, 'w', encoding='utf-8') as fp:
    fp.write(text)
print('done.')
