#!/usr/bin/env python
# -*- coding:utf8 -*-

import socket
s = socket.socket()
host = socket.gethostname()
port = 1234
s.bind((host, port))

s.listen(5)
while True:
	c, addr = s.accept()
	print 'GET CONNECT FROM :', addr
	c.send('Thank you for connecting')
	c.close()