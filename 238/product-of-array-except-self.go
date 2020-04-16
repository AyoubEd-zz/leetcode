func productExceptSelf(nums []int) []int {
	pref := 1
	res := make([]int, len(nums))
	for i, _ := range res {
		res[i] = 1
	}

	for i, num := range nums {
		res[i] *= pref
		pref *= num
	}

	pref = 1

	for i := len(nums) - 1; i >= 0; i-- {
		res[i] *= pref
		pref *= nums[i]
	}

	return res

}
