from socket import *
import sys

if len(sys.argv) <= 1:
	print('Usage : "python ProxyServer.py server_ip"\n[server_ip : It is the IP Address Of Proxy Server')
	sys.exit(2)
# Create a server socket, bind it to a port and start listening
tcpSerSock = socket(AF_INET, SOCK_STREAM)
# Fill in start.
tcpSerSock.bind(('', 8888))
tcpSerSock.listen(1)
# Fill in end.
while True:
	# Strat receiving data from the client
	print 'Ready to serve...'
	tcpCliSock, addr = tcpSerSock.accept()
	print('Received a connection from:', addr)
	message = tcpCliSock.recv(1024)
	filename = message.split(' ')[1][1:]
	fileexisted = False
	print(filename)
	try:
		f = open(filename, 'r')
		fileexisted = True
		while True:
			line = f.readline()
			if not line: break
			tcpCliSock.send(line)
		f.close()
	except IOError:
		fileexisted = False
		proxy_cliSock = socket(AF_INET, SOCK_STREAM)
		print(sys.argv[1])
		proxy_cliSock.connect((sys.argv[1], 80))
		header = u'GET /' + filename + ' HTTP/1.1\nConnection: close\n\n'
		proxy_cliSock.sendall(header)
		f = open(filename, 'a')	
		while True:
			res = proxy_cliSock.recv(2048)
			if len(res):
				tcpCliSock.send(res)
				f.write(res)
			else:
				break
		f.close()
		tcpCliSock.close()
tcpSerSock.close()
