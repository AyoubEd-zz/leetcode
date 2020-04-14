func maxSubArrayLen(nums []int, k int) int {
	mx, sum := 0, 0
	mp := map[int]int{0: -1}

	for index, num := range nums {
		sum += num

		if prevIndex, ok := mp[k-sum]; ok {
			mx = max(index-prevIndex, mx)
		}

		if _, ok := mp[-sum]; !ok {
			mp[-sum] = index
		}
	}

	return mx
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

