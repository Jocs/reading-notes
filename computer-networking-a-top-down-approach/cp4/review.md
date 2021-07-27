R1: 

- 数据报

- 路由器中有三个网络分层结构，但是链路交换机只负责两层网络分层结构。

A router forwards a packet based on the IP(layer 3) address, but a link-layer switch forwards a packet based on the MAC(layer 2) address.

R2:

在数据报网络中，两个主要的功能是：转发和路由选择。在虚电路网络中，网络层的三个主要功能是，虚电路的建立、数据传输、虚电路拆除。

Datagram based network layer: forwarding and routing.

R3:

路由转发是指将分组从一个输入端口转送到一个输出连接，转发是在单一的路由器中完成。而路由选择是指确定分组从源主机到目的主机的路由路径，根据路由选择协议及算法，来确定 forwarding table。

Forwarding is about moving one packet from the router input port to the appropriate output port, and the routing is about to determine the path from the source router to destination router.

R4:

是的都是用转发表：虚电路的转发表（略）

路由器的转发表：使用最长前缀匹配规则。

R5:

因特网提供的 best effort service，分组间的定时不能被确保证的，分组接受的顺序也不能保证和发送的顺序一致，传输的分组也不能保证一定被交付。

CBR 和 ABR 略。CBR 更牛逼。。。

R6:

电话

R7:

查表更快，避免集中式的处理。

With the shadow copy, the forwarding lookup is made locally, at each input port and without invoking the centralized routing processor. Such a decentralized lookup avoid centralized lookup bottleneck at a single point within the router.

R8:

互联网络的交换结构

Switching via memory, switching via a bus, switching via an interconnection network, and the interconnection network can forward packets in parallel as long as the packets are been forwarded to different output ports.

R9:

在输入端口，缓存是有限的，当缓存满的时候，再来的分组就有可能被丢弃（弃尾）。通过加快处理速率来消除分组丢失。

R10:

原因同上，不能。

Note that increasing switch fabric process rate can to avoid the this problem from occurring.

R11:

HOL 阻塞是线路前部阻塞，他是出现在输入连接，是指在同一个输入连接，前面的分组阻塞了后面分组的传输，即使后面的分组的输出端口无竞争。

R12
有 IP 地址，个数等于输入连接和输出连接的总和。

Yes, They have one address for each interface.

R13

略

R14:

略

R15:

8 个接口，三个转发表。

R16:

60 个字节，应用数据所在百分比：40 / 60 = 66.67%

R17:

在 IP 报文段中有一个协议头的字段，用来存储上层所使用的协议，比如 17 是 UDP，6 是 TCP。

The 8 bit protocol field is used to determine which transport layer protocol to use, the destination host should pass the segment to.

R18:

使用 DHCP 来动态分配地址，使用了 NAT 技术。

Typically the wireless router use the DHCP server to distribute the IPs to the 5 PCs, Yes, wireless router also use NAT technology as it obtains only one address from the IPS.

R19:

IPV4 和 IPV6 有类似的字段：

比如 版本号

流量类型

在 IPV4 中有一个数据报长度，是指首部加上数据长度的总和，而在 IPV6 中有一个有效荷载长度。

在 IPV4 中有一个协议头字段，用来表示上层使用哪一种运输层协议，而在 IPV6 中也有类似的字段，叫做下一个首部，用来表示该数据报中的内容需要交付给哪个协议。

源和目的地 IP 地址（但是表示方式不一样，一个时 32 bit 一个时 128 bit）

数据

寿命或者跳限制。

R20:

不同意，其实还是网络层协议，只是将 IPV6 的数据报封装成了 IPV4 的数据报，然后在 channel 中传输。

Yes, Because the entire IPV6 datagram is encapsulated in an IPV4 datagram.

R21:

- 报文复杂性，链路状态算法报文更加复杂，DV 算法仅当新的链路费用导致了与改链路相连的节点的最低费用路径发生改变时，才传播已改变的链路费用。

- 收敛速度：DV 算法收敛速度较慢，有可能会遇到选择环路，DV 算法还会遭到无穷计数的问题。

- 健壮性，LS 算法更加健壮。

R22:

在因特网中，通过一种被称为自治系统（Autonomous System）机制来控制规模扩大的问题，一个 AS 是有多台路由器相连组织而成，AS 与 AS 之间通过网关路由器相连，一个 AS 系统可能包含多个子网。

R23:

是必要的

No, each AS has administrative autonomy for routing within an AS.

R24:

略

R25:

RIP 使用 UDP 作为其运输层协议，而 OSPF 是直接使用 OSPF 报文段，其封装在 IP 数据报之上，因此，它也自己实现了数据的可靠传输以及其它的一些运输层功能。

R26:

AS 数

R27:

考虑到规模和管理自治的问题.

R28:

?

R29:

子网：具有相同 IP 前缀组成的一个网络，我们可以将链接路由器的链路剪开，这样就形成了一系列的孤岛，每一个孤岛就是一个子网。

前缀：IP 地址前面一部分。

BGP路由，通过其它 AS 可达的子网信息，同时像 AS 内部广播这些可达信息，选择最好的路径。

R30:

AS_PATH: 该属性包含了前缀通告已经通过的那些 AS.

NEXT-HOP: 是一个 开始某 AS-PATH 的路由器接口。

R31:

略

R32: 通过单播来实现广播，发送节点向每个目的地分别发送分组的副本，在给定 N 个目的节点的情况下，源节点只是产生了该分组的 N 份副本。通过单播方式来实现广播，效率比较低。同时 N 次单播的一个隐含假设是广播的接收方及其地址均为发送方所知。

而支持广播的单个网络，经第一跳，仅发送分组的单个副本，然后让第一跳后面的其它端点生成并转发任何所需的副本。

R33

a: 

| 无控制洪泛 | 受控洪泛 | 生成广播树 |
| ----- | ---- | ----- |
| 会     | 会    | 不会    |

b:

| 无控洪泛 | 受控洪泛 | 生成广播树 |
| ---- | ---- | ----- |
| 会    | 不会   | 不会    |

R34:

不同，只用加入到一个多播组，多播组通过一个简介地址来编址。

R35:

用来建立一个多播树。

R36

共享树多播路由选择构建单一的，共享的路由选择树，以路由所有发送方的分组，而第二种方法为多播组中每个源构建一颗多播路由选择树。
