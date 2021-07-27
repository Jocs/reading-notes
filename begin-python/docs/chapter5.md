##条件、循环和其他语句
```python
import logging
logging.basicConfig(level=logging.INFO, filename='resultlog.log')
info = logging.info
```
###5.1print 和 import 的更多信息
print 可以连续打印多个值，用逗号隔开
```python
print 1,3,4
```
import 的一些高级用法
```python
from math import sqrt
from math import sqrt as mathSqrt
```
###5.2赋值魔法
####5.2.1序列解包
序列解包和 javascript 中的结构复制很像
```python
x, y, z = [1, 2, 3]
print x, y, z
d = {'name': 'jocs', 'age': 34}
x, y = d.popitem()
print x, y
```
####5.2.2链式赋值
就是将同一个值赋值给多个变量
```python
x = y = 'hello'
print x, y
```
####5.2.3增量赋值
```python
x = 1
x += 1
x -= 1
x *= 5
x /= 5
print x
```
###5.3语句块
在 python 中，通过冒号 : 开始一个代码块，代码块需要进行缩进，当缩进结束，代码块也就结束
###5.4条件和条件语句
####5.4.1 真值和假值
在 python 中， False, None, '', [], {}, 0 都是假值，其它是真值
```python
print False == None # 虽然以上都是假值但是本身不相等。
```
####5.4.2条件执行和 if 语句
```python
name = raw_input('what is your name: ')
if name.endswith('j'):
  print 'end with j'
else: print 'not end with j'
```
####5.4.5 嵌套代码块
```python
name = raw_input('U name: ')
if name.endswith('s'):
  if name.startswith('j'):
    print 'jocs'
  elif name.startswith('f'):
    print 'fs'
else:
  print 'not find'
```
####5.4.6更加复杂的条件
* x == y
* x < y
* x > y
* x != y # 和 x <> y 效果相同，但是后者不推荐使用
* x is y
* x is not y
* x in y
* x not in y
== 和 is 有什么区别呢？==判断值是否相等，而 is 需要是同一个引用。
####5.4.7 断言
```python
age = 34
assert(age == 34), 'The age is not 34'
```
###5.5循环
####5.5.1 while 循环
```python
x = 1
while x in range(0, 12):
  print x
  x += 1
```
####5.5.2 for 循环
```python
words = ['noce', 'key', 'value']
for word in words:
  print word
```
range 和 xrange 有什么区别呢？xrange 是惰性序列
####5.5.3循环遍历字典元素
```python
d = {'name': 'jocs', 'age': 23}
for key in d:
  print 'key is %s, value is %s' % (key, d[key])
for key, value in d.items():
  print key, value
```
####5.5.4 一些迭代工具
1. 并行迭代
```python
name = ['jocs', 'ransixi', 'wujingwen']
x = xrange(0, 100000000)
for na, n in zip(name, x):
  info(na + str(n))
```
2. 按索引迭代
```python
import string
for index, n in enumerate(string.letters):
  print 'letter %s is at position %d' % (n, index)
```
####5.5.5跳出循环
跳出循环有两个一种是 countine 该关键字只会跳出当前循环体，进入下一个循环，而 break 会跳出整个循环
 while True 的用法
```python
x = 1
while True:
  print x
  if x > 20: break
  x += 1
```
####5.5.6 循环中的 else 语句
```python
for n in range(39, 37, -1):
  root = sqrt(n)
  if root == int(root):
    print n
    break
else: print 'not found'
```
###5.6 列表推导式
列表推导式是用其他列表创建新的列表，在 Haskell 中也有列表推导式，可惜，在 javascript 中没有。
```python
print [x * x for x in range(0, 4)]
girls = ['xiaohua', 'xiaoyun', 'meimei']
boys = ['xiaoming', 'xiaohuang']
x = [(b, g) for b in boys for g in girls]
print x
```
###5.7 pass\del\exec 的使用
```python
scope = {}
exec('sqrt = 1') in scope
print sqrt(4)
print scope['sqrt']
 
```