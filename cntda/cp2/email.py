from socket import *
msg = "I love computer networks!"
contenttype = "text/plain"
endmsg = "\r\n.\r\n"
# Choose a mail server (e.g. Google mail server) and call it mailserver 
mailserver = 'smtp.126.com' #Fill in start   #Fill in end
# Create socket called clientSocket and establish a TCP connection with mailserver
#Fill in start
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((mailserver, 25))
#Fill in end
recv = clientSocket.recv(1024)
print(recv)
if recv[:3] != '220':
  print('220 reply not received from server: connect.')

# Send HELO command and print server response.
heloCommand = 'HELO Alice\r\n'
clientSocket.send(heloCommand.encode())
recv1 = clientSocket.recv(1024)
print(recv1)
if recv1[:3] != '250':
  print('250 reply not received from server.: hello')

# Auth
authCommand = 'AUTH LOGIN\r\n'
clientSocket.send(authCommand.encode())
recv2 = clientSocket.recv(1024)
print(recv2)
if recv2[:3] != '334':
  print('334 replay not received from server.: auth')

# set username and password
username = 'bHVvcmFuMTk4OEAxMjYuY29t\r\n'
password = '******\r\n'
clientSocket.sendall(username)
recv3 = clientSocket.recv(1024)
print(recv3)
if recv3[:3] != '334':
  print('334 replay not received from server.: username')

clientSocket.sendall(password)
recv4 = clientSocket.recv(1024)
print(recv4)
if recv4[:3] != '235':
  print('235 replay not received from server.: password')

# Send MAIL FROM command and print server response.
# Fill in start
fromCommand = 'MAIL FROM: <luoran1988@126.com>\r\n'
clientSocket.sendall(fromCommand.encode())
recv5 = clientSocket.recv(1024)
print(recv5)
if recv5[:3] != '250':
  print('250 replay not received from server.: mail from')
# Fill in end

# Send RCPT TO command and print server response.
# Fill in start
toCommand = 'RCPT TO: <ransixi@gmail.com>\r\n'
clientSocket.sendall(toCommand.encode())
recv6 = clientSocket.recv(1024)
print(recv6)
if recv6[:3] != '250':
  print('250 replay not received from server.: mail to')
# Fill in end

# Send DATA command and print server response.
# Fill in start
dataCommand = 'DATA\r\n'
clientSocket.send(dataCommand.encode())
recv7 = clientSocket.recv(1024)
print(recv7)
if recv7[:3] != '250':
  print('250 replay not received from server.: data')
# Fill in end

# Send message data.
fromaddress = 'luoran1988@126.com'
toaddress = 'ransixi@gmail.com'
subject = 'email from script'
message = 'from:' + fromaddress + '\r\n'
message += 'to:' + toaddress + '\r\n'
message += 'subject:' + subject + '\r\n'
message += 'Content-Type:' + contenttype + '\t\n'
message += '\r\n' + msg
clientSocket.sendall(message.encode())

# Message ends with a single period.
clientSocket.sendall(endmsg.encode())
recv9 = clientSocket.recv(1024).decode()
print(recv9)
if (recv9[:3] != '250'):
	print('250 reply not received from server')


# Message ends with a single period.
# Fill in start
clientSocket.sendall('QUIT\r\n'.encode())
# Fill in end

# Send QUIT command and get server response.
# Fill in start
clientSocket.close()
# Fill in end