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
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        vector<int> v;
        return maxInTree(root, v);
    }
    
    bool maxInTree(TreeNode* root, vector<int>& v) {
        if(root->left) {bool f = maxInTree(root->left, v); if(!f) return false;}
        if(v.size()>0 && root->val <= v[v.size()-1]) return false;
        v.push_back(root->val);
        if(root->right) {bool f = maxInTree(root->right, v); if(!f) return false;}
        return true;
    }
};
