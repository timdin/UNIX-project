from BeautifulSoup import BeautifulSoup
#from mechanize import mechanize
import mechanize
import urllib2

br = mechanize.Browser()
br.set_handle_robots(False)

html = br.open('http://new.comicvip.com/show/cool-103.html?ch=23-11')
res = urllib2.urlopen('http://new.comicvip.com/show/cool-103.html?ch=23-11')
html2 = res.read()

soup = BeautifulSoup(html.read())
soup2 = BeautifulSoup(html2)

#print (soup.prettify())

print (soup.find(id = 'logo').get('src'))

print (soup.find(id = 'TheImg').get('src'))#it should get the comic picture
print (soup2.find(id = 'TheImg').get('src'))#it should get the comic picture


#print (soup.find(name = 'TheImg')['name'])

#print (soup.find_all('img'))