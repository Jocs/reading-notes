P1: 

a: wrong

b: wrong => true

c: wrong

d: wrong, 应该是相应时间

e: wrong

P2:

CDUP - Change to Parent Directory
SMNT - Structure Mount
STOU - Store Unique
RMD - Remove Directory
MKD - Make Directory
PWD - Print Directory
SYST - System

etc

P3: DNS  和 UDP 协议。

P4: a: http://gai.a.cs.umass.edu/cs453/index.html 

b: 1.1

c: 持续链接

d:不知道，需要通过DNS 查询

e: Mozilla, **为什么需要浏览器类型？**

P5:

a: 能够找到，时间是 Tue,07 Mar 2008

b: Sat， 10 Des2005 18:27:46

c: 3874 字节

d:  '<!doc', 是持续链接

P6:

a: Connection: close, 用来关闭一个连接。

b: HTTPS or TSL

c: 可以。

d: 不可以，服务器端已经关闭连接。

P7: ~~2N + 1~~

P8: 

a:16 RTT

b: 4RTT

c：9RTT

P9:

P13: MAIL FROM 有 “<>” 包围。

P14: 在 SMTP 中，客户通过只发送一个只包含一个句点的行，向服务器支持报文的结束。

在 HTTP 协议中，是怎么做到结束报文的呢？

P15: 

?

P16:

?

P17:

P18:

略

P19:

P20:

不知道。

P21:

P22:

(1) P2P 的情况：T >= Max{ NF / (us + sum(u)), F / dmin, F / us }

(2) Client & Server 的情况：T >= Max{ NF / us,  F/dmin }

P23:

a) 分别向每个对等方传递数据。

b) 并行向 N 个对等方传递文件，大家都是用相等的速率。

c) 因此最小分发时间不可能比 NF / us 和 F/Dmin 还大。

P24:

a) 由于 Dmin 很大，因此 T >= Max{ NF/(US + SUM(u)), F/US }，又因为 US 小于 (us + u1 + u2) / N.所以 T >= F/US。当 server 将第一个 比特传给一个对等方时，对等方就将这个比特以最大上传速率传给其它对等方，同时其它的对等方收到后，有传给其它的对等方。

b）同上。

c）略

P25:

边：N(N - 1)

节点是什么？

P26:

？

P27:

4 是其第一个后继，8 是其第二个后继。

P28:

向 15 发送一条 TCP 请求，15 继续向 1 发送请求，依次进行直到找到第一个小于节点的 8，然后插入 8的前面。还需要更新4，5，8，10 的前继或者后继。

P31:

a TCPClient 连接不上 Server

b 数据包丢失，

c 链接不上或者数据发送不到目的地的 server

P32:

不用修改，UDPClient 的端口号是 5432，UDPServer 的端口号 12000。在变化之前，不知道 UDPClient 的端口号，UDPServer 的端口号依然是 12000.

P33:

优点是更快的显示页面，缺点，服务器压力变大。

P34:

TCP 字节流保证了数据的准确和有序，但是缺点是发送数据效率低。

P35:

不知道

P36:

键是分配的编号，值是下载或者上传的文件。


