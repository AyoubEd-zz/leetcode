func findMaxLength(nums []int) int {
	mp := make(map[int]int, len(nums)+1)
	mp[0] = -1
	max, sum := 0, 0

	for index, num := range nums {
		if num == 1 {
			sum += 1
		} else {
			sum += -1
		}

		if prevIndex, ok := mp[sum]; ok {
			if index-prevIndex > max {
				max = index - prevIndex
			}
		} else {
			mp[sum] = index
		}
	}

	return max
}
