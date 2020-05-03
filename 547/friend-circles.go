var arr, siz []int

func findCircleNum(M [][]int) int {
	circles := len(M)
	arr, siz = make([]int, len(M)), make([]int, len(M))
	for i := 0; i < len(M); i++ {
		arr[i] = i
		siz[i] = 1
	}

	for i := 0; i < len(M); i++ {
		for j := 0; j < len(M[0]); j++ {
			if M[i][j] == 1 && !arefriends(i, j) {
				circles--
				union(i, j)
			}
		}
	}

	return circles
}

func root(i int) int {
	for arr[i] != i {
		i = arr[i]
	}
	return i
}

func arefriends(i, j int) bool {
	return root(i) == root(j)
}

func union(i, j int) {
	a, b := root(i), root(j)
	sa, sb := siz[a], siz[b]

	if sa > sb {
		arr[b] = a
		siz[a] += siz[b]
	} else {
		arr[a] = b
		siz[b] += siz[a]
	}
}
