import requests
import json

id_url = 'http://scxk.nmpa.gov.cn:81/xk/itownet/portalAction.do?method=getXkzsList'

data = {
    'on': 'true',
    'page': '1',
    'pageSize': '15',
    'productName': '',
    'onditionType': '1',
    'applyname': '',
    'applysn': ''
}

headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) '
                  'Chrome/88.0.4324.190 Safari/537.36 '
}

json_ids = requests.post(id_url, data, headers=headers).json()
# print(json_ids)

id_list = []
for dic in json_ids['list']:
    id_list.append(dic['ID'])

detail_url = 'http://scxk.nmpa.gov.cn:81/xk/itownet/portalAction.do?method=getXkzsById'
detail_data_list = []
for id in id_list:
    data = {
        'id':id
    }
    detail_json = requests.post(detail_url,data, headers=headers).json()
    detail_data_list.append(detail_json)

with open('.\\EnterpriseDetailData.json', 'w', encoding='utf-8') as fp:
    json.dump(detail_data_list, fp, ensure_ascii=False)

print('done')
