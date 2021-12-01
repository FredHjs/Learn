import requests
from bs4 import BeautifulSoup

url = 'https://www.shicimingju.com/book/sanguoyanyi.html'
headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) '
                  'Chrome/88.0.4324.190 Safari/537.36 '
}
page_text = requests.get(url, headers=headers).text.encode('ISO-8859-1')

soup = BeautifulSoup(page_text, 'lxml')
li_list = soup.select('.book-mulu > ul > li')
fp = open('.\\sanguo.txt', 'w', encoding='utf-8')
for li in li_list:
    title = li.a.text
    detail_url = 'https://www.shicimingju.com/' + li.a['href']

    page_content = requests.get(detail_url, headers=headers).text.encode('ISO-8859-1')
    detail_soup = BeautifulSoup(page_content, 'lxml')
    div_tag = detail_soup.find('div', class_='chapter_content')
    chapter_content = div_tag.get_text()
    fp.write(title + ':' + chapter_content + '\n')
    print(title, "done")
