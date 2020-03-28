func maxArea(height []int) int {
    max, surface, i, j, ti, tj := 0, 0, 0, len(height) - 1, 0, 0
    
    for i<j {
        
        if height[j] > height[i] {
            surface = height[i] * (j - i)
            
            // find the next taller vertical line
            ti = i
            i+=1
            for i<j && height[i]<=height[ti]{
                i += 1
            }
            
        } else {
            surface = height[j] * (j - i)
            
            // find the last taller vertical line before the current one
            tj = j
            j -= 1
            for i<j && height[j]<=height[tj]{
                j -= 1
            }
            
        }
        
        if surface > max {
            max = surface
        }
        
    }
    
    return  max
}

