func lengthOfLongestSubstring(s string) int {
	mx := 0
	mp := make(map[byte]int, len(s))
	i, j := 0, 0

	for ; j < len(s); j++ {

		if idx, ok := mp[s[j]]; ok && idx >= i {
			mx = max(j-i, mx)
			i = idx + 1
		}

		mp[s[j]] = j
	}

	mx = max(j-i, mx)

	return mx
}

func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}
