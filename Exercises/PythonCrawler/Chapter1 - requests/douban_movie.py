import requests
import json

url = 'https://movie.douban.com/j/chart/top_list'

params = {
    'type': '24',
    'interval_id': '100:90',
    'action': '',
    'start': '0',
    'limit': '100'
}

headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) '
                  'Chrome/88.0.4324.190 Safari/537.36 '
}

response = requests.get(url, params, headers=headers)

res_json = response.json()

with open('.\\豆瓣.json', 'w', encoding='utf-8') as fp:
    json.dump(res_json, fp, ensure_ascii=False)

print('done.')


