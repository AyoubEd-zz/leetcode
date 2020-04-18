const base = 16777619

func hash(s string) uint32 {
	var h uint32
	for i := 0; i < len(s); i++ {
		h = (h*base + uint32(s[i]))
	}
	return h
}

func nexthash(h uint32, x, c byte, mult uint32) uint32 {
	h = h - mult*uint32(x)
	h = h*base + uint32(c)
	return h
}

func strStr(haystack string, needle string) int {
	if len(needle) > len(haystack) {
		return -1
	}

	hn := hash(needle)
	hh := hash(haystack[:len(needle)])
	if hn == hh {
		if check(haystack[0:len(needle)], needle) {
			return 0
		}
	}

	var mult uint32 = 1 // mult = base^(len(needle)-1)
	for i := 0; i < len(needle)-1; i++ {
		mult = (mult * base)
	}

	for i := len(needle); i < len(haystack); i++ {
		hh = nexthash(hh, haystack[i-len(needle)], haystack[i], mult)

		if hh == hn {
			if check(haystack[i-len(needle)+1:i+1], needle) {
				return i - len(needle) + 1
			}
		}
	}

	return -1
}

func check(s, t string) bool {
	for i := 0; i < len(s); i++ {
		if s[i] != t[i] {
			return false
		}
	}

	return true
}

