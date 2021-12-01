from selenium.webdriver import Chrome
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.chrome.options import Options
from Chaojiying_Python.chaojiying_Python.chaojiying import Chaojiying_Client
import time

# initialize chaojiying
chaojiying = Chaojiying_Client('13654988091', 'qwer1234!@#$', '920553')

# however, the website would check if the browser is opened by selenium...

option = Options()
option.add_argument('--disable-blink-features=AutomationControlled')

web = Chrome(options=option)

web.get('https://kyfw.12306.cn/otn/resources/login.html')
time.sleep(3)

web.find_element_by_xpath('/html/body/div[2]/div[2]/ul/li[2]/a').click() # switch to password login
time.sleep(3)

code_img_element = web.find_element_by_xpath('//*[@id="J-loginImg"]')

dic = chaojiying.PostPic(code_img_element.screenshot_as_png, 9004)

result_coordinates = dic['pic_str']
# print(result_coordinates)
coordinates_list = result_coordinates.split('|')
for co in coordinates_list:     #in the form of x,y
    p_temp = co.split(',')
    x = int(p_temp[0])
    y = int(p_temp[1])
    # move the mouse to the certain coordinate on the code image
    ActionChains(web).move_to_element_with_offset(code_img_element, x, y).click().perform()

time.sleep(1)
# enter username and password
web.find_element_by_xpath('//*[@id="J-userName"]').send_keys('123456789')
web.find_element_by_xpath('//*[@id="J-password"]').send_keys('qwertyuio')

web.find_element_by_xpath('//*[@id="J-login"]').click()
time.sleep(3)
# drag the verify block
block = web.find_element_by_xpath('//*[@id="nc_1_n1z"]')
ActionChains(web).drag_and_drop_by_offset(block, 300, 0).perform()
