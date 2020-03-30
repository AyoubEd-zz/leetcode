func threeSumClosest(nums []int, target int) int {
    sol := 0
    sums := map[int][]int{}
    
    minDiff := math.MaxFloat64
    
    for i:=0 ; i<len(nums)-1 ; i++ {
        for j:=i+1 ; j<len(nums) ; j++ {
            sums[nums[i]+nums[j]] = []int{i, j}
        }
    }
    
    for key, value := range sums {
        for i:=0 ; i<len(nums) ; i++ {
            if i != value[0] && i != value[1] {
                if minDiff > math.Abs(float64(key + nums[i] - target)) {
                    minDiff = math.Abs(float64(key + nums[i] - target))
                    sol = key + nums[i]
                } 
            }
        }
    }
    
    return sol
}
