from socket import *

serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind(('', 1234))

print('Server listen at 1234 port')

while True:
  message, clientAddress = serverSocket.recvfrom(2)
  while len(message) > 0:
    print(message.decode())
    message, clientAddress = serverSocket.recvfrom(2)
    print(message.decode())

serverSocket.close()