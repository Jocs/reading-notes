## 文件和流
### 11.1 打开文件
打开文件使用 open 方法
```python
for char in open('./text.txt'):
	print char
```
####11.1.1 文件模式
如果 open 只带一个文件名参数，那么我们可以获取得能读取文件内容的文件对象。
open 方法支持5 中模式。`r` `w` `a` `+` `b`
####11.1.2 缓存
当参数为 0 时，不缓存，当参数不为 0 缓冲。当参数为 -1 时，使用默认的缓冲区大小。
###11.2 基本的文件方法
文件对象是指支持 file 类方法的对象，最重要的是支持read 方法和 write 方法。
####11.2.1 读和写
```python
f = open('./text.txt', 'w')
f.write('ransixi\n')
f.write('jocs@126.com\n')
f.close()
f = open('./text.txt', 'r')
print f.read(4)
print f.read()
f.close()
```
####11.2.2 管道输出
####11.2.3 读写行
```python
f = open('./text.txt', 'r')
print f.readline()
f.close()
f = open('./text.txt', 'r')
for line in f.readlines():
	print '#' + line
f.close()
f = open('./text.txt', 'w')
lines = [
	'hello\n',
	'nice to meet you\n',
	'my name is ransixi'
]
f.writelines(lines)
f.close()
f = open('./text.txt', 'w')
f.write('nice to meet you\n')
f.write('my name is jocs\n')
f.close()
```
####11.2.5 基本的文件方法
###11.3 对文件内容进行迭代
```python
def process(string):
	print 'Process: ' + string
f = open('./text.txt')
while True:
	s = f.read(1)
	if not s:
		break
	process(s)
f.close()
f = open('./text.txt')
while True:
	line = f.readline()
	if not line:
		break
	process(line)
f.close()
f = open('./text.txt')
for line in f.readlines():
	process(line)
f.close()
print list(open('./text.txt'))
```