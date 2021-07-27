from socket import *

serverSocket = socket(AF_INET, SOCK_STREAM)
serverSocket.bind(('', 1234))
serverSocket.listen(1)

while True:
  connectSocket, addr = serverSocket.accept()
  message = connectSocket.recv(1024)
  print(message)
  res = 'HTTP/1.1 200 OK\r\n\r\nhello world'
  try:
    connectSocket.sendall(res)
  except:
    connectSocket.close()

serverSocket.close()