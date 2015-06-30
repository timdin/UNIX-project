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

print "searching..."

#open the homepage
browser = webdriver.Firefox()
browser.get('http://comicvip.com/')

#type in the serach
box = browser.find_element_by_id('k')
box.send_keys(search)

#click in the first result
button = browser.find_element_by_id('bt')
webdriver.ActionChains(browser).move_to_element(button).click(button).perform()

print "search done!"

res = browser.find_element_by_xpath("//td[2]/a")
webdriver.ActionChains(browser).move_to_element(res).click(res).perform()

print "entering comic index"

vol_list = browser.find_elements_by_class_name('Vol')
vol_data = {}
for v in vol_list:
	vol_data[v.get_attribute("id")[1:]] = v.text
	print vol_data[v.get_attribute("id")[1:]]

epi_list = browser.find_elements_by_class_name('Ch')
epi_data = {}
for e in epi_list:
	epi_data[e.get_attribute("id")[1:]] = e.text
	print epi_data[e.get_attribute("id")[1:]]

script = browser.find_element_by_id("c1").get_attribute('onclick')

browser.execute_script(script)


for handle in browser.window_handles:
	browser.switch_to_window(handle)

base = browser.current_url[:-1]

browser.quit()
display.stop()

download_range_input = raw_input("Please input the chapter you would like to download.\n ex: 111, 222, 444-555, 666\n")
token = download_range_input.split(',')
download_range = []

for tt in token:
	tt = tt.strip()
	if not '-' in tt:#regular number
		download_range.append(int(tt))
	else:#do the range
		download_range += range(int(tt.split("-")[0]), int(tt.split("-")[1])+1)

print download_range
		
with codecs.open('url_list.txt', 'w', "utf-8") as f:
	f.write("%s\n" % search)
	f.write("%s\n" % base)
	#print 'Vols:'
	for vid, vtext in vol_data.iteritems():
		if int(vid) in download_range:
			f.write("%s\n"%(vid))
	#print 'Episodes:'
	for eid, etext in epi_data.iteritems():
		if int(eid) in download_range:
			f.write("%s\n"%(eid))
