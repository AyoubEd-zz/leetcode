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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()) {
          auto p = q.front();
          if(result.size() == p.second) result.push_back({});
          result[p.second].push_back(p.first->val);
          q.pop();

          if((p.first)->left != nullptr) {
            q.push({p.first->left, p.second + 1});
          }

          if((p.first)->right != nullptr) {
            q.push({p.first->right, p.second + 1});
          }
        }

        return result;
    }
};