func maxProfit(prices []int) int {
    mn := 1 << 32
    max_profit := 0
    
    for _, val := range prices {
        mn = min(mn, val)
        max_profit = max(max_profit, val - mn)
    }
    
    return max_profit
}

func max(i, j int) int {
    if i >= j {
        return i
    }
    
    return j
}

func min(i, j int) int {
    if i < j {
        return i
    }
    
    return j
}

