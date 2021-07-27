package intset

import (
	"bytes"
	"fmt"
)

// IntSet 正整数集合
type IntSet struct {
	words []uint64
}

// Has 判断 s 中是否包含 x 元素
func (s *IntSet) Has(x int) bool {
	word, bit := x/64, uint64(x%64)
	return word < len(s.words) && s.words[word]&(1<<bit) != 0
}

// Add 向整数集中添加一个数
func (s *IntSet) Add(x int) {
	word, bit := x/64, uint64(x%64)
	for word >= len(s.words) {
		s.words = append(s.words, 0)
	}
	s.words[word] |= 1 << bit
}

// UnionWith 求 s 和 t 的交集
func (s *IntSet) UnionWith(t *IntSet) {
	for i, tword := range t.words {
		if i < len(s.words) {
			s.words[i] |= tword
		} else {
			s.words = append(s.words, tword)
		}
	}
}

// UnionSet 求交集
func (s *IntSet) UnionSet(t *IntSet) IntSet {
	var u IntSet
	for i, tword := range t.words {
		if i < len(s.words) {
			for i+1 > len(u.words) {
				u.words = append(u.words, 0)
			}
			u.words[i] = s.words[i] & tword
		}
	}
	return u
}

func (s *IntSet) String() string {
	var buf bytes.Buffer
	buf.WriteByte('{')
	for i, word := range s.words {
		if word == 0 {
			continue
		}
		for j := 0; j < 64; j++ {
			if word&(1<<uint(j)) != 0 {
				if buf.Len() > len("{") {
					buf.WriteByte(' ')
				}
				fmt.Fprintf(&buf, "%d", 64*i+j)
			}
		}
	}
	buf.WriteByte('}')
	return buf.String()
}
