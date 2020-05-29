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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) return res;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        int last_lvl = -1;
        while(!q.empty()) {
            pair<TreeNode*, int> pr = q.front();
            q.pop();
            TreeNode* node = pr.first;
            int level = pr.second;
            
            if(level == last_lvl) res[res.size()-1] = node->val;
            else { 
                res.push_back(node->val);
                last_lvl = level;
            }

            if(node->left) {
                q.push(make_pair(node->left, level+1));
            }
            if(node->right) {
                q.push(make_pair(node->right, level+1));
            }
        }
        return res;
    }
};
