##异常
###8.1 什么是异常
 Python 中使用异常对象来表示异常
 ###8.2 按自己的方式出错
 可以使用 raise 关键字手动抛出异常
 > raise Exception
 ###8.3 捕获异常
 使用 try/except 语句来捕获异常
```python
x = 5
y = 0
try:
  x / y
except ZeroDivisionError:
  print 'the second number cannot be 0'
```
捕获到的异常可以重新通过 raise 抛出
```python
class Calculator:
  throw = False
  def dev(self, x, y):
    try:
      return x / y
    except ZeroDivisionError:
      if self.throw:
        raise
      else:
        print 'the second number can not be 0'
  def changeStatus(self):
    self.throw = not self.throw
c = Calculator()
c.dev(4, 0)
c.changeStatus()
try:
  c.dev(4, 0)
except ZeroDivisionError:
  print 'yaha it throw an error'
```
###8.4 try...except 模块还可以有不止一个 except 语句
```python
def dev(x, y):
  try:
    print x / y
  except ZeroDivisionError:
    print 'Zero ERROR'
  except TypeError:
    print 'not number'
dev('2', 2)
dev(3, 0)
```
###8.5 用一个块捕获两个异常
```python
try:
  x = 0
  y = '4'
  x / y
except(ZeroDivisionError, TypeError, NameError):
  print 'some error occur'
```
###8.6 捕获错误对象
```python
try:
  x = 0
  y = '4'
  x / y
except(ZeroDivisionError, TypeError, NameError), e:
  print e
```
###真正的全捕捉
```python
try:
  x = 0
  y = '4'
  x / y
except:
  print 'error'
```
###8.8 try/except 可以加一个 else 语句
```python
while True:
  try:
    x = 1 # input('Enter a number: ') I dont want write number
    y = 3 # input('Enter a number: ')
    print x / y
  except:
    print 'error occur try angin'
  else:
    break
```
###8.9 可以添加 finally 语句
```python
x = None
try:
  x = 1 / 0
except:
  print 'occur error another time'
finally:
  print 'must print'
```
###8.11 异常禅道
条件语句和异常处理的选择？一个是前置判断，一个是后置判断。貌似 python 更推荐使用异常处理。。。