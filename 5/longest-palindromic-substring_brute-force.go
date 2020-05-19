/* Brute force solution */
func longestPalindrome(s string) string {
	mx, sub := 0, ""
	for i := 0; i < len(s); i++ {
		for j := i; j < len(s); j++ {
			if ok := valid(s[i : j+1]); ok {
				if mx < j-i+1 {
					mx = j - i + 1
					sub = s[i : j+1]
				}
			}
		}
	}
	return sub
}

func valid(s string) bool {
	i, j := 0, len(s)-1
	for i < j {
		if s[i] != s[j] {
			return false
		}
		i++
		j--
	}
	return true
}
