#!/usr/bin/env python
# -*- coding:utf8 -*-

from urllib import urlretrieve, urlcleanup

urlretrieve('https://segmentfault.com/', './segmentfault.html')
urlcleanup()
