func isValid(s string) bool {
	st := []rune{}
	mp := map[rune]rune{')': '(', ']': '[', '}': '{'}

	for _, char := range s {
		if val, ok := mp[char]; ok && len(st) > 0 && val == st[len(st)-1] {
			st = st[:len(st)-1]
		} else if ok && (len(st) == 0 || val != st[len(st)-1]) {
			return false
		} else {
			st = append(st, char)
		}
	}

	return len(st) == 0
}
