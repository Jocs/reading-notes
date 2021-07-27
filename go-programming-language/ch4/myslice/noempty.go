package myslice

// Noempty 过滤 strings 中的空字符串
func Noempty(strings []string) []string {
	i := 0
	for _, item := range strings {
		if item != "" {
			strings[i] = item
			i++
		}
	}

	return strings[:i]
}

// NoEmpty2 过滤 strings 中的空字符串 第二种方法
func NoEmpty2(strings []string) []string {
	out := strings[:0]
	for _, s := range strings {
		if s != "" {
			out = append(out, s)
		}
	}
	return out
}

// Remove 移除 slice 中的某个元素
func Remove(strings []string, i int) []string {
	copy(strings[i:], strings[i+1:])
	return strings[0 : len(strings)-1]
}
