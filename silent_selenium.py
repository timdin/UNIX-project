#!/usr/bin/env python

from pyvirtualdisplay import Display
from selenium import webdriver
from bs4 import BeautifulSoup

display = Display(visible = 0, size = (800, 600))
display.start()

browser = webdriver.Firefox()
browser.get('http://new.comicvip.com/show/cool-103.html?ch=586-2')

print browser.title

soup = BeautifulSoup(browser.page_source)
print (soup.find(id='TheImg').get('src'))#expect to get the comic pic...

for option in soup.find_all('option')
	print option['value']#this will get a list of all pages

browser.quit()

display.stop()
