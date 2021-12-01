import requests
from lxml import etree
import csv
from concurrent.futures import ThreadPoolExecutor

fp = open('.\\data.csv', 'w', encoding='utf-8', newline='')
csvwriter = csv.writer(fp)


def download_one_page(url):
    res = requests.get(url)
    html = etree.HTML(res.text)
    data_table = html.xpath('/html/body/div[2]/div[4]/div[1]/table')[-1]
    tr_list = data_table.xpath('./tr[position()>1]')
    for tr in tr_list:
        text = tr.xpath('./td/text()')
        text = (item.replace('\\', '').replace('/', '') for item in text)
        csvwriter.writerow(text)
    print(url, 'done')


if __name__ == '__main__':
    # download_one_page('http://www.xinfadi.com.cn/marketanalysis/0/list/1.shtml')
    with ThreadPoolExecutor(50) as t:
        for i in range(1, 200):
            t.submit(download_one_page, url=f'http://www.xinfadi.com.cn/marketanalysis/0/list/{i}.shtml')
    print('all download done.')
