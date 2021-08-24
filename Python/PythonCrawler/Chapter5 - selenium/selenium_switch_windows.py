from selenium.webdriver import Chrome
from selenium.webdriver.common.keys import Keys
import time

web = Chrome()

web.get('http://lagou.com')

web.find_element_by_xpath('//*[@id="cboxClose"]').click()
time.sleep(1)

web.find_element_by_xpath('//*[@id="search_input"]').send_keys('python', Keys.ENTER)
time.sleep(1)

web.find_element_by_xpath('//*[@id="s_position_list"]/ul/li[1]/div[1]/div[1]/div[1]/a/h3').click()
# here, a new tab is opened, so we need to switch to the new one

web.switch_to.window(web.window_handles[-1])

job_detail = web.find_element_by_xpath('//*[@id="job_detail"]/dd[2]/div').text

print(job_detail)

web.close()     # although the curret window is closed, we still need to switch to the original window
web.switch_to.window(web.window_handles[0])

print(web.find_element_by_xpath('//*[@id="s_position_list"]/ul/li[1]/div[1]/div[1]/div[1]/a/h3').text)

# for webpages with iframe
# web.get('https://91kanju.com/vod-play/541-2-1.html')
# iframe = web.find_element_by_xpath('//*[@id="player_iframe"]')
# web.switch_to.frame(iframe)
#
# text = web.find_element_by_xpath('//*[@id="sub-frame-error-details"]').text
# print(text)
# web.switch_to.default_content()