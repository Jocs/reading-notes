#!/usr/bin/env python
# -*- coding:utf8 -*-


# ##更加抽象
# ###对象的魔力
# * 多态： 可以对不同类的对象使用相同的操作
# * 封装： 对外部世界隐藏对象的工作细节
# * 继承： 以通用的类为基础建立专门的对象
# ####7.1.1 多态
# 下面是一些多态函数
print 'abc'.count('a')
print [1, 2, 3, 1].count(1)
1 + 1
[1, 2, 3] + ['a']
# ####7.1.2 封装

class OpenObject:
  def setName(self, name):
    self.name = name
  def getName(self):
    return self.name
person = OpenObject()
person.setName('JOCS')
print person.getName()

# ###7.2 类和类型
# ####7.2.3 特性、函数、方法
# 方法将他们的第一个参数绑定到实例上，当然也可以将特定的函数绑定到某个特性上面，这样就不会有特殊的 self 参数了：
class Class:
  def method(self):
    print 'i have a self'
def function():
  print 'i have not a self'
c = Class()
c.method()
function()
c.method = function
c.method()
# 在 JavaScript 中，对象的方法可以赋值给其他变量，但是此时的 this 值就改变了，而 python 并不会改变 self.举个例子：

class Bird:
  song = 'SQQ'
  def sing(self):
    print self.song 
b = Bird()
b.sing()
another_sing = b.sing
another_sing()

# 在 python 中通过双下划线将一个特性或方法声明为私有的：
class Dog:
  __name = 'joc'
  def setName(self):
    print self.__name 
d = Dog()
d.setName()
print d._Dog__name # 这是魔法代码，依然可以访问类的私有特性

# ####7.2.4 类的命名空间
#  lambda 表达式
foo = lambda x: x * x
print foo(4)
# 另外一个例子
class MemberCounter:
  member = 0
  def init(self):
    MemberCounter.member += 1
m1 = MemberCounter()
m1.init()
print MemberCounter.member
m2 = MemberCounter()
m2.init()
print MemberCounter.member
print m1.member # 和 JavaScript 的静态属性不一样，JS 中静态属性是构造函数的属性，而不是实例的属性
print m2.member

# ####7.2.5 指定超类
# 通过在类名后面加括号来制定超类
class Filter:
  def init(self):
    self.blocked = []
  def filter(self, seq):
    return [x for x in seq if x not in self.blocked]
class SPAFilter(Filter):
  def init(self):
    self.blocked = ['SPA']
f = SPAFilter()
f.init()
print f.filter([1, 2, 'SPA'])

# ####7.2.6 检查继承
print issubclass(SPAFilter, Filter)
print issubclass(Filter, SPAFilter)
print SPAFilter.__bases__
print isinstance(f, SPAFilter)

# ####7.2.7 多个超类
class Annimal:
  def say(self):
    print 'i am animal'
class Tree:
  def say(self):
    print 'i an tree'

class Me(Annimal, Tree): #前面的类方法会把后面的类方法覆盖
  pass
me = Me()
me.say()

# ####7.2.8 接口和内省
print hasattr(me, 'say')
print callable(getattr(me, 'say', None))
print me.__dict__













