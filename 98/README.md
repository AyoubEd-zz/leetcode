## Validate Binary Search Tree

Given a binary tree, determine if it is a valid binary search tree (BST).

- - -

An inorder traversal of a valid BST yields the values in the tree sorted.<br>
We keep the inorder traversal trace in a array and at each node we verify if it's value is greater than the last value in that array.
