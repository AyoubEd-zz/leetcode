## Binary Tree Right Side View

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

- - -

Perform a BFS while keeping track of the level in the tree. Since in our BFS we go from the left to the right, we keep overwriting the value that will appear in each level. The last value that will be written is the value if the rightmost node in that level.
