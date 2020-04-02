func threeSum(nums []int) [][]int {
    if len(nums) < 3 {
        return [][]int{}
    }
    
    sort.Ints(nums)
    mp := map[int]bool{}
    solutions := [][]int{}
    sum := 0
    
    for i:=0 ; i<len(nums)-1 ; i++ {
        if nums[i] == nums[i+1] && nums[i]!=0 {mp[-1*nums[i]] = true}
        if i<len(nums)-2 && nums[i] == nums[i+2] {mp[-1*nums[i]] = true}
        
        for j:=i+1 ; j<len(nums) ; j++ {            
            sum = nums[i] + nums[j]
            
            if _, ok := mp[sum]; ok {
                solutions = append(solutions, [][]int{{-1*sum, nums[i], nums[j]}}...)
            } 
            
            for j < len(nums) -1 &&  nums[j] == nums[j+1] {j++}

        }
        
        mp[-1*nums[i]] = true
        
        for i < len(nums)-1 && nums[i] == nums[i+1] {i++}
    }
    
    return solutions
}
