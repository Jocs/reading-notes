#!/usr/bin/env python
# -*- coding:utf8 -*-

import unittest, chapter16

class SquareTestCase(unittest.TestCase):
  def testInterers(self):
    for x in xrange(-10, 10):
      p = chapter16.square(x)
      self.failUnless(p == x * x, 'interger square failed')
  def testFloat(self):
    for x in xrange(-10, 10):
      x = x / 10.0
      p = chapter16.square(x)
      self.failUnless(p == x * x, 'Float square failed')

if __name__ == '__main__': unittest.main()