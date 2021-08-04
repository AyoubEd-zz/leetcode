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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr)
            return result;
        queue<TreeNode*> q;
        q.push(root);
        int dir = 1;

        while(!q.empty()) {
          deque<int> tmp;
          auto l = q.size();

          while(l--) {
            auto a = q.front();
            q.pop();

            if(dir == 1) tmp.push_back(a->val);
            else tmp.push_front(a->val);

            if(a->left != nullptr) {
              q.push(a->left);
            } 

            if(a->right != nullptr) {
              q.push(a->right);
            }
          }

          vector<int> tt;
          while(!tmp.empty()) {
            tt.push_back(tmp.front());
            tmp.pop_front();
          }

          result.push_back(tt);
          dir *= -1;
        }

        return result;
    }
};