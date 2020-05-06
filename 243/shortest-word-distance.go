import "math"

func shortestDistance(words []string, word1 string, word2 string) int {
	min := (1 << 32) - 1
	a, b := -1, -1

	for index, word := range words {
		if word == word1 {
			a = index
		} else if word == word2 {
			b = index
		}
		if (word == word1 || word == word2) && a != -1 && b != -1 {
			min = getmin(min, getAbs(b-a))
		}
	}

	return min
}

func getAbs(a int) int {
	f := float64(a)
	return int(math.Abs(f))
}

func getmin(a, b int) int {
	if a < b {
		return a
	}
	return b
}
