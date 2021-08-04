import requests
import json

url = 'https://passport.17k.com/ck/user/login'

data = {
    'loginName': 'j462huan',
    'password': 'huang111'
}
session = requests.session()
res = session.post(url, data=data)

# print(res.cookies)
bookshelf_url = 'https://user.17k.com/ck/author/shelf?page=1&appKey=2406394919'
bookshelf = session.get(bookshelf_url)

with open('.\\bookshelf.json', 'w', encoding='gbk') as fp:
    json.dump(bookshelf.json(), fp, ensure_ascii=False)

print('done.')