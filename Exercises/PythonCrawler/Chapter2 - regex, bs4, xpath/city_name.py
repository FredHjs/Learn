import requests
from lxml import etree

url = 'https://www.aqistudy.cn/historydata/'

headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) '
                  'Chrome/88.0.4324.190 Safari/537.36 '
}

page_text = requests.get(url, headers=headers).text

tree = etree.HTML(page_text)
####################### 解析一次
all_city_names=[]
a_list = tree.xpath('//div[@class="bottom"]/ul/li/a | //div[@class="bottom"]/ul/div[2]/li/a')        #热门城市与普通城市
for a in a_list:
    city_name = a.xpath('./text()')[0]
    all_city_names.append(city_name)
print(all_city_names, len(all_city_names))


####################### 解析两次
# hot_cities = tree.xpath('//div[@class="bottom"]/ul/li')
# all_city_name_list = []
# for li in hot_cities:
#     hot_city_name = li.xpath('./a/text()')[0]
#     all_city_name_list.append(hot_city_name)
#
# all_cities = tree.xpath('//div[@class="bottom"]/ul/div[2]/li')
# for li in all_cities:
#     city_name = li.xpath('./a/text()')[0]
#     all_city_name_list.append(city_name)
#
# print(all_city_name_list, len(all_city_name_list))
