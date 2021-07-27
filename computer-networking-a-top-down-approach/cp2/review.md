R1: 

Web - HTTP

email -> SMTP\POP3\IMAP

FTP -> FTP

R2:

网络体系结构是固定的，并未应用程序提供特定的服务集合。应用程序结构主要有两种：

- 客户-服务器体系

- 对等体系结构 P2P

R3:

对于 Web 而言，浏览器是客户，服务器进程是服务器。在不同应用中客户和服务器有所不同，在有些应用者，它既可能是客户又可能是服务器，比如CDN。

R4:

不同意。

R5:

IP 地址和端口号。

R6:

UDP，虽然UDP 是 unreliable 的，但是它不是建立在连接的基础上，不需要握手阶段，因此会更快。

R7:

IM 应用？多人游戏应用？

R8:

运输层主要提供如下四种宽泛的服务；

1. 可靠的数据传输（TCP）

2. 吞吐量（运输协议没有提供）

3. 定时（运输协议没有提供）

4. 安全性(SSL ，但是 SSL 不属于运输层协议)

R9:

属于应用层协议。

R10:

握手的作用是确保建立连接，保证后面的数据通信和传输。

R11:

因为他们都需要确保数据准备可靠的传输。

R12:

主要分为四个步骤：

- 首先服务端会判断是否带有 cookie，没有就添加一个 set-cookie 的 response header。

- set-cookie 会将会话 cookie 保存在浏览器端，之后每次向服务端请求都会带上之前设置的 cookie

- 服务端根据 request header 来跟踪用户的状态

- 客户端的 cookie 是通过浏览器来维护的，服务端的 cookie 信息保存在数据库中。

R13:

首先当我们请求一个 object 时，我们是想 web cache server 发送请求，如果该 cache server 没有请求的对象，那么 cache server 就会想 origin server 发送请求，来拉去请求对象，这个过程被称作回源，同时 cache server 会将请求回来的 object 保存下来，并将 object 返回给 client，当 client 再次发起相同请求的时候，cache server 就直接将缓存下来的 object 返回给 client了。而不用再次向 origin server 发送请求，也就相应的减少了请求时间。

Web cache server 应该是减少了所有对象的请求时延，包括 html、js、css、图片等。

R14:

略

R15:

因为 FTP 有两个 TCP 链接，分别是 control connection 和 data connection。control connection 主要控制授权、登录、文件操作。data connection 主要是传递文件。因此FTP 是带外传递控制信息。

R16:

Alice 首先通过 HTTP 协议将 报文发送到 Alice 的邮件服务器，Alice 的邮件服务器通过 SMTP 协议将邮件内容发送到 Bob 的邮件服务器，Bob 邮件服务器将 Alice 发送的邮件投递到 Bob 的 email box 中，最后，Bob 通过 POP3 协议来拉去 Alice 发送的邮件内容。

R17:

问题是 HTTP 协议的 首部吗？

R18:

不知道

R19:

可以，MX。

R20:

略。

R21:

~~是的，这就能够不断的更新前四位上载列表，找到最优匹配的对象。~~

Bob 不一定也会给 Alice 发送 chunks，只有当 Alice 在 Bob 的前四个邻居中的时候，Bob 才会给 Alice 发送。

R22:

tracker 首先会给 Alice 一个参与对等方中的一个子集，比如说是 50 个对等方，并且 Alice 持有这 50 个对等方的 IP 地址，Alice 向这 50 个IP 地址并行发送请求，简历 TCP 连接，在这 50 个对等方中，如果有回应，将会建立 TCP  连接, 比如和 Bob 建立了连接，那么 Alice 将会从 Bob 那下载第一个块。

R23:

覆盖网络：覆盖网络是一个对等方组织成为的一个环，在这个环形设置中，每个对等方都会和他的前继和后继相连，同时也可以和其它的对等方相连。

有路由器吗：不包括路由器，其实覆盖网络是建立在计算机网络之上的虚拟网络。

边是什么：不是物理链路，而是一条虚拟的联络。

R24:

首先我们说下环形 DHT 的缺点，为了找到负责的键，DHT 中所有的 N 个节点都必须绕环转发报文，平均发送 N/2 条报文。

建立所有对等方链接的 DHT 的缺点，为了查询某个负责的键，需要创建 N - 1 条链接。

因此在每个对等方必须跟踪的邻居数量与 DHT 为解析一个查询而需要发送的报文数量之间存在一个折中。

R25:

文件分布、即使通讯、视频电话、文件下载、分布式计算

R26:

因为 TCP 是建立在连接的基础上的，因为需要建立连接，所以在 client 简历一个 client Socket 去 connect server 的时候，需要将源IP, Port 和 目的 IP，Port 发送到 Server 端，Server 根据这个四元组创建一个唯一标识的 socket，Server 可以通过这个 socket 向 client 发送报文，client 也可以通过 client 端的 socket 来向 Server 端发送报文，这就是所谓的建立连接。这也是 TCP server 端需要为连接另外建立一个 socket 的原因，如果有 n 个 client 连接，那么 Server 端就需要建立 n + 1 个连接。

R27:

在建立在 TCP 协议上的应用，服务端需要先运行，这样 client 才能够建立连接。这样才能保证消息准备可靠的传输到 服务端。这也是 TCP 协议提供的保证。

而在 UDP 协议上的应用，因为 UDP 本来就只是在 IP 协议上加了多路复用和多路分解，并不能保证消息准确送达，所以就无所谓了。
