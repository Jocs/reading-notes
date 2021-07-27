package word2

import (
	"math/rand"
	"unicode"
)

// IsPalindrome 判断字符串是否是回文
func IsPalindrome(s string) bool {
	var letters []rune
	for _, r := range s {
		if unicode.IsLetter(r) {
			letters = append(letters, unicode.ToLower(r))
		}
	}
	for i := range letters {
		if letters[i] != letters[len(letters)-1-i] {
			return false
		}
	}

	return true
}

// 返回随机的回文字符串
func randomPalindrome(rng *rand.Rand) string {
	// 字符串最大长度是 25
	maxLen := rng.Intn(25)
	var runes = make([]rune, maxLen)
	for i := 0; i < (maxLen+1)/2; i++ {
		r := rune(rng.Intn(0x1000))
		runes[i] = r
		runes[maxLen-1-i] = r
	}
	return string(runes)
}
