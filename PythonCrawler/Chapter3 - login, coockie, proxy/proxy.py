import requests
# touches some edges of law - gray area - not recommended
# used when a very big amount of requests need to be sent in a short time period
# 218.60.8.83:3129 - found on proxies web resource
proxy = {
    'https': 'https://218.60.8.83:3129'
}
res = requests.get('http://www.baidu.com', proxies=proxy)

res.encoding = 'utf-8'
print(res.text)