#!/usr/bin/env python
# -*- coding:utf8 -*-

# ##测试
# ### 16.2 测试工具
# ####16.2.1 doctest 的使用

def square(x):
  '''
  Square a number and return the result.
  >>> square(2)
  4
  >>> square(4)
  16      
  '''
  return x * x

if __name__ == '__main__':
  import doctest, chapter16
  doctest.testmod(chapter16)