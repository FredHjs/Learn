from selenium.webdriver import Chrome

web = Chrome()

web.get('https://replit.com/')

print(web.title)
