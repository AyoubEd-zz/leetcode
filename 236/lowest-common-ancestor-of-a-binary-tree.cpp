/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    pair<TreeNode*, int> countt(TreeNode* root, TreeNode* p, TreeNode* q){
        int i = 0;
        pair<TreeNode*, int> L;
        pair<TreeNode*, int> R;
        
        if(root == p || root == q) i++;
        if(root->left) { L = countt(root->left, p, q); i += L.second; }
        if(root->right) { R = countt(root->right, p, q); i += R.second; }
                
        TreeNode* n = nullptr;
            
        if(i == 2) {
            if(L.first != NULL) n = L.first;
            else if(R.first != NULL) n = R.first;
            else n = root;
        }
        
        return make_pair(n, i);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* d) {
        pair<TreeNode*, int> pr = countt(root, p, d);
        return pr.first;
    }
};
