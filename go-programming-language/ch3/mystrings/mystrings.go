package mystrings

// HasPrefix 判断字符串是否还有另外一个字符串作为 prefix
func HasPrefix(s, prefix string) bool {
	return len(s) >= len(prefix) && s[:len(prefix)] == prefix
}

// HasSuffix 判断字符串 s 是否包含另外一个子串作为 suffix
func HasSuffix(s, suffix string) bool {
	return len(s) >= len(suffix) && s[len(s)-len(suffix):] == suffix
}

// Contains judge
func Contains(s, substr string) bool {
	sLen := len(s)
	for i := 0; i < sLen; i++ {
		if HasPrefix(s[i:], substr) {
			return true
		}
	}

	return false
}
