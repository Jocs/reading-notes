from socket import *

clientSocket = socket(AF_INET, SOCK_DGRAM)

message = "abcdefsososoososososososso"

clientSocket.sendto(message.encode(), ('localhost', 1234))
modifiedMessage, serverAddress = clientSocket.recvfrom(2048)
print(modifiedMessage)

clientSocket.close()