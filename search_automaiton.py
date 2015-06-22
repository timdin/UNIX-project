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
	vol_data[v.get_attribute("id")] = v.text
	#print vol_data[v.get_attribute("id")]

epi_list = browser.find_elements_by_class_name('Ch')
epi_data = {}
for e in epi_list:
	epi_data[e.get_attribute("id")] = e.text
	#print epi_data[e.get_attribute("id")]

script = browser.find_element_by_id("c1").get_attribute('onclick')

browser.execute_script(script)


for handle in browser.window_handles:
	browser.switch_to_window(handle)

print browser.current_url

with codecs.open('url_list.txt', 'w', "utf-8") as f:

	f.write("%s\n" % browser.current_url[:-1])
	#print 'Vols:'
	for vid, vtext in vol_data.iteritems():
		f.write("%s\t%s\n"%(vid, vtext))
	#print 'Episodes:'
	for eid, etext in epi_data.iteritems():
		f.write("%s\t%s\n"%(eid, etext))
browser.quit()

display.stop()
