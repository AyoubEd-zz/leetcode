func lengthOfLongestSubstring(s string) int {
    //Treating empty strings
    if len(s) == 0 {
        return 0
    }
    
    max := 1
    char_last_position := map[rune]int{}
    
    second_pointer := 0
    for first_pointer, char := range s {
        if last_position, ok := char_last_position[char]; ok && last_position >= second_pointer {
            second_pointer = last_position + 1
        }
        
        char_last_position[char] = first_pointer
        if first_pointer - second_pointer + 1> max {
            max = first_pointer - second_pointer + 1
        }
    }
    
    return max
}
