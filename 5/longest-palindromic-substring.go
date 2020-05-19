/* Extend around center */

func longestPalindrome(s string) string {
	mx, start := 1, 0

	for i := 0; i < len(s); i++ {
		if st, ln := extendPalindrom(s, i, i); ln > mx {
			mx, start = ln, st
		}
		if st, ln := extendPalindrom(s, i, i+1); ln > mx {
			mx, start = ln, st
		}
	}

	return s[start : start+mx-1]
}

func extendPalindrom(s string, i, j int) (int, int) {
	for i >= 0 && j < len(s) && s[i] == s[j] {
		i--
		j++
	}
	return i + 1, j - i
}
