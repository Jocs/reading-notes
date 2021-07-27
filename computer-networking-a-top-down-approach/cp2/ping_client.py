from socket import *
import time

serverName = '127.0.0.1'
serverPort = 12000
socketClient = socket(AF_INET, SOCK_DGRAM)
socketClient.settimeout(1)

for i in range(0, 10):
  sendTime = time.time()
  message = ('Ping %d %s' % (i + 1, sendTime)).encode()
  try:
    socketClient.sendto(message, (serverName, serverPort))
    modifiedMessage, serverAddress = socketClient.recvfrom(1024)
    rtt = time.time() - sendTime
    print('Sequence %d: Reply from %s    RTT = %.3fs' % (i+1, serverName, rtt))
  except Exception as e:
    print('Sequence %d timeout' % (i + 1))
socketClient.close()

