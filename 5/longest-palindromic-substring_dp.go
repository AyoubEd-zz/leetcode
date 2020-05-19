/* DP solution */
func longestPalindrome(s string) string {
	if len(s) == 0 {
		return ""
	}

	dp := make([][]bool, len(s))
	for i, _ := range dp {
		dp[i] = make([]bool, len(s))
	}

	start, end := 0, 0

	for i := len(s) - 1; i >= 0; i-- {
		for j := i; j < len(s); j++ {
			dp[i][j] = s[i] == s[j] && (j-i < 3 || dp[i+1][j-1])

			if dp[i][j] && j-i+1 > end-start+1 {
				start, end = i, j
			}
		}
	}
	return s[start : end+1]
}
