from selenium.webdriver import Chrome
from selenium.webdriver.common.keys import Keys
import time
web = Chrome()

web.get('http://lagou.com')

el = web.find_element_by_xpath('//*[@id="changeCityBox"]/p[1]/a')
el.click()
time.sleep(0.5)       # block the program for some time so the webpage can refresh, especially when the page contains
                        # ajax (one disadvantage of selenium - slow)

input_box = web.find_element_by_xpath('//*[@id="search_input"]').send_keys('python', Keys.ENTER)

li_list = web.find_elements_by_xpath('//*[@id="s_position_list"]/ul/li')
time.sleep(1)
for li in li_list:
    job_title = li.find_element_by_tag_name('h3').text
    salary = li.find_element_by_xpath('./div/div/div/[2]/div/span').text
    print(job_title, salary)