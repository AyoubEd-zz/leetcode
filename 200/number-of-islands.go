func numIslands(grid [][]byte) int {
	islands := 0

	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[0]); j++ {
			if grid[i][j] == '0' {
				continue
			}

			islands++
			bfs(grid, i, j)
		}
	}

	return islands
}

var dir = [6][2]int{[2]int{-1, 0}, [2]int{0, -1}, [2]int{0, 1}, [2]int{1, 0}}

func bfs(grid [][]byte, i, j int) {
	grid[i][j] = '0'

	for _, di := range dir {
		x, y := i+di[0], j+di[1]

		if x >= 0 && y >= 0 && x < len(grid) && y < len(grid[0]) && grid[x][y] == '1' {
			bfs(grid, x, y)
		}
	}
}

