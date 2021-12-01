import requests
from lxml import etree

url = 'https://bj.58.com/ershoufang/'

headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) '
                  'Chrome/88.0.4324.190 Safari/537.36 '
}

page_text = requests.get(url, headers=headers).text

tree = etree.HTML(page_text)
property_list = tree.xpath('//div[@class="property"]')
# print(property_list[0].xpath('.//div[@class="property-content-title"]/h3/text()'))
with open('.\\58_title.txt', 'w', encoding='utf-8') as fp:
    for div in property_list:
        title = div.xpath('.//div[@class="property-content-title"]/h3/text()')[0]
        price_num = div.xpath('.//span[@class="property-price-total-num"]/text()')[0]
        price_text = div.xpath('.//span[@class="property-price-total-text"]/text()')[0]
        fp.write(title + '\t' + '\t' + '\t' + price_num + price_text + '\n')

print('done')

