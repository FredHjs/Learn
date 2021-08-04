# to deal with verify codes, we can use a third-party code recognition platform
# here we chose chaojiying.com
# this demo uses service of chaojiying.com to deal with the login verify code on chaojiying.com (lol)
from selenium.webdriver import Chrome
from Chaojiying_Python.chaojiying_Python.chaojiying import Chaojiying_Client
import time

web = Chrome()

web.get('http://www.chaojiying.com/user/login/')
# recognize the code
img = web.find_element_by_xpath('/html/body/div[3]/div/div[3]/div[1]/form/div/img').screenshot_as_png

chaojiying = Chaojiying_Client('13654988091', 'qwer1234!@#$', '920553')
dic = chaojiying.PostPic(img, 1902)

code = dic['pic_str']

# fill in username and password
web.find_element_by_xpath('/html/body/div[3]/div/div[3]/div[1]/form/p[1]/input').send_keys('13654988091')
web.find_element_by_xpath('/html/body/div[3]/div/div[3]/div[1]/form/p[2]/input').send_keys('qwer1234!@#$')
web.find_element_by_xpath('/html/body/div[3]/div/div[3]/div[1]/form/p[3]/input').send_keys(code)
time.sleep(5)
# click on login button
web.find_element_by_xpath('/html/body/div[3]/div/div[3]/div[1]/form/p[4]/input').click()
