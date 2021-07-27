##自带电池
 Python 标准安装中包括一组模块，称为标准库。
####10.1.4 包
为了组织好模块，我们可以将模块分组为包。包基本是另外一类模块，有趣的它能够包含其他模块。
###10.3 标准库：一些最爱
####10.3.1 sys模块
sys 模块让你能够访问与 Python 联系紧密的变量和函数。
```python
from sys import argv, exit, modules, path, platform, stdin, stdout, stderr
print argv # 用于打印参数
print path # 字符串列表，import 模块是就是从列表中找文件
print platform
```
####10.3.2 os 模块
```python
from os import environ, system, sep, pathsep, linesep, urandom
```
ystem('/Applications/Google\ Chrome.app/Contents/MacOS/Google\ Chrome') # 代开 chrome 浏览器
```python
print sep
print pathsep
print linesep
print urandom(8)
import webbrowser
```
ebbrowser.open('/Applications/Google\ Chrome.app/Contents/MacOS/Google\ Chrome')
####10.3.3 fileinput 模块
```python
import fileinput
for line in fileinput.input():
	line = line.rstrip()
	num = fileinput.lineno()
	print '%-40s # %2i' % (line, num)
```
####10.3.4 集合、堆、双端队列
1. 集合
```python
print set(range(10))
a = set([1, 2, 3])
b = set([2, 3, 4])
print a.union(b) # 求并集
print a | b # 求并集
print a.intersection(b) # 求交集
print a & b # 求交集
print a.difference(b)
print a - b # 在 a 但是不在 b 中
print a.symmetric_difference(b) # 亦或
print a ^ b
mySets = []
for i in range(10):
	mySets.append(set(range(i, i + 5)))
print reduce(set.union, mySets) # set.union 是个方法
```
2. 堆是一个很骚的数据结构
他是一个优先队列，同时其又是一个完全二叉树。python 中有一个模块叫做 heapq,包括堆的一些方法
```python
from heapq import heappush, heappop, heapify, heapreplace, nlargest, nsmallest
from random import shuffle
data = range(10)
shuffle(data)
heap = []
for n in data:
	heappush(heap, n)
print heap
heappush(heap, 0.5)
print heap
heap2 = [1, 2, 9, 4, 5, 6, 7]
heapify(heap2)
print heap2
```
3. 双端队列
```python
from collections import deque
q = deque(range(5))
q.append(5)
q.appendleft(6)
print q
q.pop()
print q
q.popleft()
q.rotate(3)
print q
```
####time 模块
```python
from time import *
str = asctime()
print str
tup = strptime(str)
str2 = asctime(tup)
print str2
print localtime(mktime(tup))
print mktime(tup)
```
####10.3.6 random 模块
```python
values = range(1, 11) + 'Jack,Queen,King'.split(',')
suits = ['diamonds', 'clubs', 'spades', 'hearts']
deck = ['%s of %s' % (v, s) for v in values for s in suits]
shuffle(deck)
while (len(deck) >= 50): print deck.pop()
```
####10.3.7 shelve 模块
shelve 模块用来存储数据
```python
import shelve
s = shelve.open('test.dat')
s['x'] = [1, 2, 3, 4]
temp = s['x']
temp.append(5)
s['x'] = temp
print s['x']
```
####10.3.8 re 模块
> 有些人面临一个问题是回想：我知道，可以使用正则表达式来解决这个问题。于是现在他们就有两个问题了。
```python
from re import *
str = 'ransixi'
if search(r'ran', str):
	print 'found it'
print match('p', 'python')
some_text = 'hello,world nice...to meet!you?haha'
print split(r'([,\s.\!\?]+)', some_text) # 如果使用捕获分组是，匹配到的结果字符串也将在结果数组中
print findall(r'[a-zA-Z]+', some_text)
print escape('!?.[](){}*+abcd')
```
3. 匹配对象和组
```python
m = match(r'w+\.([a-z]+)\..{3}', 'www.baidu.com')
print m.group(1)
print m.start(1)
print m.end(1)
print m.span(1)
```
4. 作为替换的组号和函数
```python
emphasis_pattern = r'\*([^\*]+)\*'
print sub(emphasis_pattern, r'<em>\1</em>', '*hello* - *world*') # 和 js 中 replace 方法类似
```
贪婪和非贪婪模式？
在量词后面加一个·？·就是非贪婪模式
6. 末班系统实例
```python
feild_pat = compile(r'\[(.+?)\]') # 非贪婪匹配
scope = {}
def replacement(match):
	code = match.group(1)
	try:
		return eval(code, scope)
	except SyntaxError:
		exec code in scope
		return ''
lines = []
for line in fileinput.input():
	lines.append(line)
text = ''.join(lines)
print feild_pat.sub(replacement, text)
exit() # 用于退出程序
```