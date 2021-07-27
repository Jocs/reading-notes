##第二章：列表和元组
###2.1 序列的操作
```python
fourth = raw_input('Year: ')[3]
print fourth
```
分片
```python
number = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
partial = number[2:-2]
print partial
print number[-3:]
```
复制序列
```python
anotherNumber = number[:]
print anotherNumber
```
步长
```python
print number[::2]
```
序列相加
```python
number2 = [1, 2, 3] + [4, 5, 6]
```
序列的乘法
```python
str1 = 'python ' * 4
print str1
print [10] * 10
print [None] * 10
```
成员资格
```python
permissions = 'rw'
print 'w' in permissions
user = ['jocs', 'ransixi']
print 'jocs' in user
database = [
  ['albert', '1234'],
  ['dilert', '4242'],
  ['smith', '7524'],
  ['jocs', '29']
]
username = raw_input('User name: ')
pin = raw_input('User pin: ')
if [username, pin] in database: print 'Access granted'
```
len\max\min 方法的使用
```python
number3 = [1, 2, 3, 4, 5]
print len(number3)
print max(number3)
print min(number3)
hello = 'hello world'
list1 = list(hello)
print list1
print '*'.join(list1)
```
基本的列表操作
删除元素
```python
names = ['jocs', 'ransixi']
del names[1]
print names
```
分片赋值
```python
perl = list('perl')
perl[2:] = list('python')
print perl
```
通过分片来添加和删除元素
```python
js = list('javascript')
js[1:1] = list('java')
print js
js[1:5] = []
print js
```
####2.3.3 列表方法
1. `append`方法用于在列表末尾追加新的对象:
```python
lst = [1, 2, 3]
lst.append(4)
print lst
```
2. `count`方法同于统计某个元素在列表中出现的次数：
```python
lis = [1, 2, 3, 4, 6, 5, 3]
print lis.count(3)
```
3. `extend`方法可以一次性在列表末尾追加另一个序列中的多个值，用新列表扩展原有列表:
```python
a = [1, 2, 3]
b = [4, 5, 6]
a.extend(b)
print a
```
4. `index`方法用于找出某个值在列表中第一个匹配的索引位置：
```python
knights = ['we', 'are', 'the', 'knight', 'who', 'say', 'ni']
print knights.index('who')
```
5. `insert`方法用于将对象插入到列表：
```python
number = [1, 2, 3, 4, 5]
number.insert(3, 'who')
print number
```
6. `pop`方法用于移除列表中的某一个元素，（默认值是最后一个），并且返回该元素的值，该函数参数为 index
```python
x = [1, 2, 3, 4]
print x.pop(3)
print x
```
7. `remove`方法用于移除列表中某个值的第一个匹配项
```python
x = [1, 2, 3, 4, 6, 'as', 4]
x.remove('as')
print x
```
8. `reverse`方法将列表的元素反向存放
```python
x = [1, 2, 3]
x.reverse()
```
9. `sort`方法用于在原位置对列表排序, *会改变原来的列表*，`sorted`方法不会改变原来列表，会返回一个新的列表
```python
x = [7, 5, 3, 1]
x.sort()
```
10. 高级排序
```python
x = ['example1.py', 'printBox.py', 'xx']
x.sort(key=len)
print x
```
###元组：不可变序列
元组和列表一样，也是一种序列，唯一不同的是，元组不可以修改。通过小括号来创建元组
1. tuple 函数将列表转化为元组
```python
x = [1, 2, 3]
print tuple(x)
print tuple('abc')
```
**练习** 创建一个 box,里面包含文字
```python
sentence = raw_input('Whatever you input: ')
screenWidth = 80
textWidth = len(sentence)
boxWidth = textWidth + 6
paddingWidth = (screenWidth - boxWidth) // 2
print '-' * screenWidth
print ' ' * paddingWidth + '|' + ' ' * boxWidth + '|'
print ' ' * paddingWidth + '|   ' + sentence + '   |' 
print ' ' * paddingWidth + '|' + ' ' * boxWidth + '|'
print '-' * screenWidth
```