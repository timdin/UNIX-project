# coding=utf-8

import mechanize

br = mechanize.Browser()
br.set_handle_robots(False)
br.set_debug_http(True)
br.set_debug_responses(True)
br.set_debug_redirects(True)

# Add User-Agent
br.addheaders = [("User-Agent", "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10_1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/39.0.2171.95 Safari/537.36")]

# Browse to login page
br.open('http://www.comicvip.com')

# Select login form
br.select_form(nr=0)

# Fill in username and password, submit
br["k"] = "海賊王"
br["button"] = "搜尋"
br.submit()

# Find out the link to mail
link_mail = [l for l in br.links() if l.url.startswith("http://www.comicvip.com")][0]

# Browse to mail page
br.follow_link(link_mail)

with open("output.htm", "w") as f:
    f.write(br.response().get_data())
