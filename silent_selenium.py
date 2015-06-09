#!/usr/bin/env python

from pyvirtualdisplay import Display
from selenium import webdriver
from BeautifulSoup import BeautifulSoup

display = Display(visible = 0, size = (800, 600))
display.start()

browser = webdriver.Firefox()
browser.get('http://new.comicvip.com/show/cool-103.html?ch=586-2')

print browser.title
#print browser.page_source

soup = BeautifulSoup(browser.page_source)
print (soup.find(id='TheImg').get('src'))#expect to get the comic pic...

browser.quit()

display.stop()
