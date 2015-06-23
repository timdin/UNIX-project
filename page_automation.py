#!/usr/bin/env python

from pyvirtualdisplay import Display
from selenium import webdriver
from bs4 import BeautifulSoup
import codecs

vol_list = []

with codecs.open('url_list.txt', 'r', "utf-8") as f:
	base_url = f.readline()
	for line in f:
		vol_list.append(line[:-1])
'''
print base_url
print vol_list
'''

display = Display(visible = 0, size = (800, 600))
display.start()

browser = webdriver.Firefox()
for vol in vol_list:
	browser.get(base_url+vol)
	#get all pages
	for option in soup.find_all('option'):
		browser.get(base_url+vol+"="+option['value'])
		soup = BeautifulSoup(browser.page_source)
		print (soup.find(id='TheImg').get('src'))#expect to get the comic pic...

	
	
browser.quit()

display.stop()
