# -*- coding: utf-8 -*-
from selenium import selenium
import unittest, time, re

class example(unittest.TestCase):
    def setUp(self):
        self.verificationErrors = []
        self.selenium = selenium("localhost", 4444, "*chrome", "http://www.comicvip.com/")
        self.selenium.start()
    
    def test_example(self):
        sel = self.selenium
        sel.open("/")
        sel.type("id=k", u"海賊王")
        sel.click("id=bt")
        sel.wait_for_page_to_load("30000")
        sel.click("//td[2]/a")
        sel.wait_for_page_to_load("30000")
    
    def tearDown(self):
        self.selenium.stop()
        self.assertEqual([], self.verificationErrors)

if __name__ == "__main__":
    unittest.main()
