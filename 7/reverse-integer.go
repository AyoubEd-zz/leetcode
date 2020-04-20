func reverse(x int) int {
	rev, md := 0, 0
	int_max, int_min := 1<<31-1, -1<<31

	for x != 0 {
		md = x % 10
		if rev > int_max/10 || (rev == int_max/10 && md > 7) {
			return 0
		}
		if rev < int_min/10 || (rev == int_min/10 && md < -8) {
			return 0
		}

		rev = rev*10 + md
		x /= 10
	}

	return rev
}
