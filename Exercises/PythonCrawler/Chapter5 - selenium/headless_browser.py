from selenium.webdriver import Chrome
from selenium.webdriver.support.select import Select
from selenium.webdriver.chrome.options import Options
import time

# configurations for chrome (not show up when running)
opt = Options()
opt.add_argument('--headless')
opt.add_argument('--disable-gpu')

web = Chrome(options=opt)

web.get('https://www.endata.com.cn/BoxOffice/BO/Year/?index.html')

select_element = web.find_element_by_xpath('//*[@id="OptionDate"]')

select = Select(select_element)     # wrap the select in HTML into an object, options are in option tags under select

for i in range(len(select.options)):
    select.select_by_index(i)
    time.sleep(2)
    table = web.find_element_by_xpath('//*[@id="TableList"]/table')
    print(table.text)
    print('============================================================')

print('done')

# get the elements(after browser processed the js code)
time.sleep(2)
print(web.page_source)

web.close()
