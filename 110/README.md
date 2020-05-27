## Balanced Binary Tree

Given a binary tree, determine if it is height-balanced.

- - -

We calculate depth recursively by calculating the depth of the right tree and the left tree. If it happens that they differ by 2 or more, we return a flag(-2), to indicate that we found an unbalanced subtree.
