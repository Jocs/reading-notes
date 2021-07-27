package linklist

// IntList 链表
type IntList struct {
	Value int
	Tail  *IntList
}

// Sum 链表求和
func (list *IntList) Sum() int {
	if list == nil {
		return 0
	}
	return list.Value + list.Tail.Sum()
}
