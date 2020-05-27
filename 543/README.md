## Diameter of Binary Tree

The diameter of a binary tree is the length of the longest path between any two nodes in a tree.

- - -

diameter = depth_right_tree + depth_left_tree + (1 for every tree that isn't null) <br>

The 1's represent the connection to each tree.<br>

We Launch one depth recursive call and take advantage of it to compute the diameter at every subtree.
