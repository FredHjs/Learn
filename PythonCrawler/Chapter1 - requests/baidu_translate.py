import json

import requests

url = 'https://fanyi.baidu.com/sug'

kw = input('enter a word:')
data = {
    'kw':kw
}
headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) '
                  'Chrome/88.0.4324.190 Safari/537.36 '
}
response = requests.post(url, data, headers=headers)

res_json = response.json()


with open('.\\' + kw + '.json', 'w', encoding='utf-8') as fp:
    json.dump(res_json,fp,ensure_ascii=False)

print('done.')



