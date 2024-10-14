/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;

        if (root == NULL)
            return rightView;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            rightView.push_back(q.front()->val);

            queue<TreeNode*> temp;

            while (!q.empty()) {
                TreeNode* top = q.front();
                q.pop();

                if (top->right != NULL) {
                    temp.push(top->right);
                }

                if (top->left != NULL) {
                    temp.push(top->left);
                }
            }

            q = temp;
        }

        return rightView;
    }
};