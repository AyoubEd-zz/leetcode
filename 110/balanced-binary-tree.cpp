/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int depth(TreeNode* root) {
        if(root == nullptr) { return -1; }
        int L = depth(root->left);
        int R = depth(root->right);
        if(abs(L - R) > 1 || L == -2 || R == -2) { return -2; }
        return 1 + max(L, R);
    }
    
    bool isBalanced(TreeNode* root) {
        return depth(root) != -2;    
    }
};
