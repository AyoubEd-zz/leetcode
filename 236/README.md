## Lowest Common Ancestor of a Binary Tree

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree. The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants.

- - -

We go through the tree recursively, and for each subtree we return 1 if we've seen p or q(the nodes for wich we are seeking the ancestor). Once we're at a node where we can say that we saw both, we return it as the lowest common ancestor.
