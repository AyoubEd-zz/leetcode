package main

import (
	"fmt"
)

func main() {
	str := "aaaaaoiuy"
	newStr := removeVowels(str)
	fmt.Println(newStr)
}

func removeVowels(str string) string {
	vowels := map[rune]bool{'a':true, 'e':true, 'i':true, 'o':true, 'u':true}
	result := []rune{}
	for _, char := range str {
		if _, ok := vowels[char]; !ok {
			result = append(result, char)
		}
	}
	return string(result)
}
