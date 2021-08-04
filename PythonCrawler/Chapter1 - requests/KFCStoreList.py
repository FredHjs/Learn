import requests
import json

url = 'http://www.kfc.com.cn/kfccda/ashx/GetStoreList.ashx?op=keyword'
kw = input('enter a city: ')
params = {
    'cname': '',
    'pid': '',
    'keyword': kw,
    'pageIndex': '1',
    'pageSize': '1'
}

headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) '
                  'Chrome/88.0.4324.190 Safari/537.36 '
}

response = requests.get(url, params, headers=headers)

res_json: dict = json.loads(response.text)
num_rows = res_json["Table"][0]["rowcount"]
# print(num_rows)
params['pageSize'] = num_rows

final_response = response = requests.get(url, params, headers=headers)
res_text = final_response.text
with open('.\\kfc.txt', 'w', encoding='utf-8') as fp:
    fp.write(res_text)

print('done')
