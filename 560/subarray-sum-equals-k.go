func subarraySum(nums []int, k int) int {

	count := 0
	presum := 0
	mp := map[int]int{}
	mp[0] = 1

	for i := 0; i < len(nums); i++ {
		presum += nums[i]

		count += mp[presum-k]
		mp[presum]++
	}

	return count
}
