## Number of Islands

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

- - -

This is a pretty standard BFS problem. Instead of using a queue to record the visited vertices, we instead change every encountered 1 with a 0 to mark it as if.
