#!/usr/bin/env python
# -*- coding:utf8 -*-

# ##Python 和 Web

# ### 15.1 屏幕抓取

# 使用正则表达式抓取网页内容
from urllib import urlopen
import re
p = re.compile('<a.*?href="(.*?)".*?>(.*?)</a>')
text = urlopen('https://liulanmi.com/').read()
for url, title in p.findall(text):
	print '%s (%s)' % (title, url)

# 使用 HTMLParser
from HTMLParser import HTMLParser

class Scraper(HTMLParser):
	in_h2 = False
	in_a = False
	def handle_starttag(self, tag, attrs):
		attrs = dict(attrs)
		if tag == 'h2':
			self.in_h2 = True
		if tag == 'a' and 'href' in attrs:
			self.in_a = True
			self.chunk = []
			self.url = attrs['href']
	def handle_data(self, data):
		if self.in_a:
			self.chunk.append(data)
	def handle_endtag(self, tag):
		if tag == 'h2':
			self.in_h2 = False
		if tag == 'a':
			if self.in_h2 and self.in_a:
				print '%s (%s)' % (''.join(self.chunk), self.url)
			self.in_a = False

text = urlopen('https://segmentfault.com/').read()
parser = Scraper()
parser.feed(text)
parser.close()









