package mystruct

type tree struct {
	value       int
	left, right *tree
}

// Sort 就地排序
func Sort(values []int) []int {
	var t *tree
	for _, v := range values {
		t = add(t, v)
	}

	return appendValue(values[:0], t)
}

func appendValue(values []int, t *tree) []int {
	if t == nil {
		return values
	}

	values = appendValue(values, t.left)
	values = append(values, t.value)
	values = appendValue(values, t.right)

	return values
}

func add(t *tree, value int) *tree {
	if t == nil {
		t = new(tree)
		t.value = value
	} else if value < t.value {
		t.left = add(t.left, value)
	} else {
		t.right = add(t.right, value)
	}

	return t
}
