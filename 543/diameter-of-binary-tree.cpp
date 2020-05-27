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
    int depth(TreeNode* root, int& d) {
        if(root == NULL) { return -1;}
        int L = depth(root->left, d);
        int R = depth(root->right, d);
        
        int local_diam = 0;
        if(root->left) {
            local_diam += 1 + L;
        }
        if(root->right) {
            local_diam += 1 + R;
        }
        
        d = max(d, local_diam);
        
        return 1 + max(L, R);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) { return 0;}
        int d = 0;
        depth(root, d);
        return d;
    }
};
