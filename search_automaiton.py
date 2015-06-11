#!/usr/bin/env python
# -*- coding: utf-8 -*-

from pyvirtualdisplay import Display
from selenium import webdriver
from bs4 import BeautifulSoup
import sys

search = sys.argv[1].decode("utf-8")

display = Display(visible = 0, size = (800,  600))
display.start()

browser = webdriver.Firefox()
browser.get('http://comicvip.com/')#open the homepage
#browser.type("id=k", search)#type in the serach
box = browser.find_element_by_id('k')
box.send_keys(search)
button = browser.find_element_by_id('bt')
webdriver.ActionChains(browser).move_to_element(button).click(button).perform()
#browser.click("//td[2]/a")#click in the first result
res = browser.find_element_by_xpath("//td[2]/a")
webdriver.ActionChains(browser).move_to_element(res).click(res).perform()

print browser.title

browser.quit()

display.stop()
