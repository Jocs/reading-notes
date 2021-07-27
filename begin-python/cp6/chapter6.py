#!/usr/bin/env python
# -*- coding:utf8 -*-

# ##抽象
# ###6.1 懒惰即美德
# ###6.2 抽象和结构
# ###6.3 创建函数

def fibs(num):
  '通过递归求斐波那契数列'
  if num == 1:
    return [0]
  elif num == 2:
    return [0, 1]
  else:
    return fibs(num - 1) + [fibs(num - 2)[-1] + fibs(num - 1)[-1]]
print fibs(5)
print fibs.__doc__

# ####6.3.2 并非真正函数的函数
# 在有些语言中（Pascal）没有返回值的函数称作「过程」，如果在 python 中没有明确的返回值，则函数隐式返回 None,类似于 JavaScript 中返回 undefined
# ###6.4 参数魔法
# ####6.4.2 我能改变参数吗？
# 字符串、数字、元组不可改变。但是序列、字典却可以改变，后者指向内存中同一块内存。
def try_to_change_n(n):
  n = 'Mr. Cumby'
n = 5
try_to_change_n(n)
print n
def try_to_change_seq(seq):
  seq.append('jocs')
seq = [1, 2, 3]
try_to_change_seq(seq)
print seq
# 1. 为什么要修改参数
def init(data):
  data['first'] = {}
  data['middle'] = {}
  data['last'] = {}

def look_up(data, label, name):
  return data[label].get(name)

def storage(data, full_name):
  token = full_name.split()
  if (len(token) < 3): token[1:1] = ['']
  labels = ('first', 'middle', 'last')
  for label, name in zip(labels, token):
    people = look_up(data, label, name)
    if people:
      people.append(full_name)
    else:
      data[label][name] = [full_name]

d = {}
init(d)
storage(d, 'ransixi jocs')
storage(d, 'luo ran xiao')
storage(d, 'luo guo ming')
print look_up(d, 'first', 'luo')

# ####6.4.3 关键字参数和默认值
def hello(greeting, name):
  print '%s, %s...' % (greeting, name)
hello(greeting='hello', name='world')
# 关键字参数可以为函数提供默认值
def hello_2(greeting = 'hello', name = 'ransixi'):
  print '%s, %s...' % (greeting, name)
hello_2()

# ####6.4.4 收集参数
def print_params(*params):
  print params
print_params(1, 2, 3, 4)
# 关键字参数和收集参数结合使用
def print_params2(x, y, z = 3, *parms1, **parms2):
  print x, y, z
  print parms1
  print parms2
print_params2(1, 2, 3, 3, 4, m = 4, n = 5)
# 参数收集的逆过程
params = {'greeting': 'hello', 'name': 'jocs'}
hello(**params)
parms1 = ['hello', 'Mr. Wang']
hello(*parms1)

# ###6.5 作用域
# 嵌套作用域 -> 闭包 -> 高阶函数
def multi(n):
  def factor(m):
    return n * m
  return factor

multi5 = multi(5)
print multi5(6)

# ###6.6 递归
# * 最小可能性问题
# * 每一个问题都可以转化为一个较小的问题
# ####6.6.1 两个经典问题：阶乘和幂

def factorial(n):
  if n == 1:
    return n
  else:
    return n * factorial(n - 1)
print factorial(3)

def power(x, n):
  if n == 0:
    return 1
  else:
    return x * power(x, n - 1)
print power(2, 3)

# ####6.6.2 另外一个经典的例子
# 二分法查找: seq 是已经按从小到大排好顺序的序列
def binary_search(seq, number, lower = 0, upper = None):
  if upper is None: upper = len(seq) - 1
  if lower == upper:
    assert number == seq[upper]
    return upper
  else:
    middle = (lower + upper) // 2
    if seq[middle] > number:
      return binary_search(seq, number, lower, middle - 1)
    else:
      return binary_search(seq, number, middle, upper)
seq = [45, 34, 67, 89]
seq.sort()
print binary_search(seq, 45, 0)









