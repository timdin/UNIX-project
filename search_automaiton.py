#!/usr/bin/env python
# -*- coding: utf-8 -*-

from pyvirtualdisplay import Display
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from bs4 import BeautifulSoup
import sys
import codecs

search = sys.argv[1].decode("utf-8")

display = Display(visible = 0, size = (800,  600))
display.start()

browser = webdriver.Firefox()
browser.get('http://comicvip.com/')#open the homepage
#type in the serach
box = browser.find_element_by_id('k')
box.send_keys(search)
button = browser.find_element_by_id('bt')
webdriver.ActionChains(browser).move_to_element(button).click(button).perform()
#click in the first result

print browser.current_url

res = browser.find_element_by_xpath("//td[2]/a")
webdriver.ActionChains(browser).move_to_element(res).click(res).perform()

print browser.current_url

browser.execute_script("cview('102-51.html',6);")


for handle in browser.window_handles:
	browser.switch_to_window(handle)

print browser.current_url


'''
base = browser.find_element_by_id("c1")

webdriver.ActionChains(browser) \
	.move_to_element(base) \
	.key_down(Keys.CONTROL) \
	.click(base) \
	.key_up(Keys.CONTROL).perform()

print base.text
for handle in browser.window_handles:
	browser.switch_to_window(handle)

print browser.current_url
'''
'''
vol_list = browser.find_elements_by_class_name('Vol')
epi_list = browser.find_elements_by_class_name('Ch')



with codecs.open('url_list.txt', 'w', "utf-8") as f:
	
	#print 'Vols:'
	for v in vol_list:
		f.write("%s	%s\n" % (v.text, v.get_attribute("id")))

	#print 'Episodes:'
	for e in epi_list:
		f.write("%s	%s\n" % (e.text, e.get_attribute("id")))
'''

browser.quit()

display.stop()