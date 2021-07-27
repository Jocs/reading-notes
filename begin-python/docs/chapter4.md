##字典：当索引不好用时
字典是 python 中唯一的内建的映射类型，字典中的值没有特殊的顺序，键可以使数字、字符串甚至是元组。
###4.1字典的使用
```python
str1 = [('name', 'jocs'), ('age', 23)]
print dict(str1)
```
###4.2 创建和使用字典
字典可以通过如下的方式创建：
```python
phonebook = {'Alice': '2345', 'Betl': '3456'}
```
####4.2.1 dict 函数
该方法用于将序列转为字典
####4.2.2 基本的字典操作
* len(d)返回d 中键值对的数量
* d[k] 返回关联到键 k 上的值
* del d[k] 用于删除制定的键值对
* k in d 用于判断键 k 是否存在于字典 d 中
```python
print len(phonebook)
print phonebook['Alice']
del phonebook['Betl']
print phonebook
print 'Alice' in phonebook
```
####4.2.3 字典格式化字符串
还是举个例子🌰
```python
template = '''
  <html>
    <heal>
      <title>%(title)s</title>
    </heal>
    <body>
      <div>%(body)s</div>
    </body>
  </html>
'''
print template % {'title': '文章的 title', 'body': '我是正文'}
```
####4.2.4 字典的方法
1. clear 方法用于清除字典中所有的键值对，代码如下：
```python
d = {'hello': 'world'}
d.clear()
print d
```
上面的代码我们并没有使用`d = {}`，因为该方法对引用无效
2. copy 方法，用于浅复制一个字典，而 copy 模块中的 deepcopy 是深度复制
下面会举一个深度复制的例子：
```python
from copy import deepcopy
x = {'job': 'sci', 'age': 345}
y = deepcopy(x)
del y['age']
print y
print x
```
4. get 方法是一个更加宽松的访问字典的方法，如果值不存在再回返回 None,当然也可以通过默认值替换 None
```python
print y.get('age', 'N/A')
print x.get('age')
```
5. has_key 方法用于判断字段是否拥有某一个 key，**Python 3.0不在包含该函数**
```python
print x.has_key('age')
```
6. items 和 iteriterms方法，前面一个是 dict函数的逆方法，后面一个方法将返回一个迭代器
```python
print x.items()
```
7. keys 和 iterkeys 方法，将返回字典的所有 key，后者会返回一个迭代器
```python
print x.keys()
```
8. pop 和 popitem 方法，前者会返回制定键的值，并且删除该键值对，后者会返回**随机**的键值对，并且删除该键值对
```python
print x.pop('age')
print x
print x.popitem()
print x
```
9. setdefault 方法，给字典设置默认值，如果值不存在设置默认值，如果值存在直接返回该键的值
```python
x.setdefault('name', 'N/A')
print x
x['name'] = 'jocs'
print x.setdefault('name', 'baba')
print x # {'name': 'jocs'}
```
10. update 方法，用于更新字典
```python
z = {'website': 'http://www.github.com/jocs'}
x.update(z)
print x # {'website': 'http://www.github.com/jocs', 'name': 'jocs'}
```