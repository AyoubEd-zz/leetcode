func findComplement(num int) int {
	n := num
	n |= n >> 1
	n |= n >> 2
	n |= n >> 4
	n |= n >> 8
	n |= n >> 16

	return num ^ n
}
