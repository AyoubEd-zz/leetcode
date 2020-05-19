/* Depth First Search
 */

func numIslands(grid [][]byte) int {
	islands := 0

	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[0]); j++ {
			if grid[i][j] == '0' {
				continue
			}

			islands++
			dfs(grid, i, j)
		}
	}

	return islands
}

var dir = [6][2]int{[2]int{-1, 0}, [2]int{0, -1}, [2]int{0, 1}, [2]int{1, 0}}

func dfs(grid [][]byte, i, j int) {
	grid[i][j] = '0'

	for _, di := range dir {
		x, y := i+di[0], j+di[1]

		if x >= 0 && y >= 0 && x < len(grid) && y < len(grid[0]) && grid[x][y] == '1' {
			bfs(grid, x, y)
		}
	}
}

/* Breadth First Search
 */

var dir = [4][2]int{[2]int{1, 0}, [2]int{0, 1}, [2]int{-1, 0}, [2]int{0, 1}}

func numIslands(grid [][]byte) int {
	res := 0

	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[0]); j++ {
			if grid[i][j] == '1' {
				res++
				queue := [][2]int{[2]int{i, j}}

				for len(queue) > 0 {
					v := queue[len(queue)-1]
					x, y := v[0], v[1]
					grid[x][y] = 1
					queue = queue[:len(queue)-1]
					for _, d := range dir {

						if a, b := x+d[0], y+d[1]; a > 0 && a < len(grid) && b > 0 && b < len(grid[0]) && grid[a][b] == 1 {
							queue = append(queue, [2]int{a, b})
						}
					}
				}
			}
		}
	}

	return res
}

