import requests
from lxml import etree

url = 'https://pic.netbian.com/4kqiche/'
headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) '
                  'Chrome/88.0.4324.190 Safari/537.36 '
}
res = requests.get(url, headers=headers)
page_text = res.text


tree = etree.HTML(page_text)
li_list = tree.xpath('//div[@class="slist"]/ul/li')

for li in li_list:
    img_src = 'https://pic.netbian.com/' + li.xpath('./a/img/@src')[0]
    img_name = li.xpath('./a/img/@alt')[0] + '.jpg'
    img_name = img_name.encode('iso-8859-1').decode('gbk')

    img_data = requests.get(img_src, headers=headers).content

# 懒得存储了。。。写入数据需要用‘wb’因为是二进制数据
