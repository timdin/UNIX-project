#!/usr/bin/env python

from pyvirtualdisplay import Display
from selenium import webdriver
from bs4 import BeautifulSoup
import codecs
import time

vol_list = []

with codecs.open('url_list.txt', 'r', "utf-8") as f:
	comic_name = f.readline()
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
browser.implicitly_wait(10)

#generate download shell
with open('download_script.sh', 'w') as dl:
	dl.write("#!/bin/bash\n")
	print ("start generating download script")
	for vol in vol_list:
		print ("getting vol: %d\n" % (vol))
		dir_path = "/home/comic"+comic_name+vol
		dl.write("mkdir "+dir_path+"\n")
		browser.get(base_url+vol)
		soup = BeautifulSoup(browser.page_source)
		#get all pages
		for option in soup.find_all('option'):
			#print option['value']
			browser.get(base_url+vol+"-"+option['value'])
			#print browser.current_url
			pagesoup = BeautifulSoup(browser.page_source)
			#print (pagesoup.find(id='TheImg').get('src'))#expect to get the comic pic...
			dl.write("wget " + pagesoup.find(id='TheImg').get('src') + " -O " + dir_path + "/" + vol + ".jpg")
			time.sleep(5)

browser.quit()
display.stop()
