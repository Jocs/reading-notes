#!/usr/bin/env python
# -*- coding:utf8 -*-

# ##使用字符串
# ###3.1基本的字符串操作
# 分片、索引、乘法、判断成员资格等，前面几章已经提到过
website = 'www.baidu.com'
print website[0:3]
# ###3.2字符串格式化精简版
format = 'Pi with three decimals: %9.3f'
from math import pi
print format % pi
# ###3.3字符串格式化完整版
# ####3.3.1简单转换
print 'Price of egg $%d' % 45
print 'My name is %s' % 'jocs'
print 'His name is %s, and work in %s' % ('ransixi', 'shanghai')

# ####3.3.2字符的宽度和精度
# 宽度和精度通过 . 来分割，也可以通过 \* 作为字段宽度或者精度，此时数值会从元组参数中获取：
print '%10.4f' % pi
print '%.5s' % 'hello world'
print '%.*s' % (5, 'hello world')
# ####3.3.3符号、对齐和用0填充
print '%010.3f' % pi
print '%-10.3f' % pi
print '% d' % 10
print '%+d' % 10
# ###3.4字符串方法
# ####3.4.1find 方法
# find 方法可以用在一个较长的字符串中查找子串，它返回子串所在位置最左端的索引，如果没有找到则返回 -1。
str1 = 'one world one dream'
print str1.find('world')
print str1.find('one', 3)
# ####3.4.2join 方法
# 其实 split 方法的逆方法，用于连接序列中的元素
seq = ['1', '2', '3']
print ' '.join(seq)
dirs = '', 'usr', 'bin', 'env'
print '/'.join(dirs)
# ####3.4.3lower 方法
#  lower 方法用于返回字符串的小写字母版本
print 'How Are You'.lower()
# ####3.4.4replace 方法用于替换字符串
print 'This is a test'.replace(' is', ' is not')
# ####3.4.5split 方法
# 它是 join 方法的逆方法，用于将字符串分割成序列
print '1+2+3+4'.split('+')
# ####3.4.7 translate 方法
# 该方法和 replace 方法类似，它的优势在于可以同时进行多个替换，有些时候比 replace 方法效率高
from string import maketrans
table = maketrans('abc', '#$%')
print 'abcde'.translate(table)










