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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);

        bool reachLastNode = false;
        while (!q.empty()) {
            queue<TreeNode*>temp;
            while (!q.empty()) {
                TreeNode* node = q.front();
                q.pop();

                if (node == NULL) {
                    reachLastNode = true;
                }else{
                    if (reachLastNode)
                        return false;
                    temp.push(node->left);
                    temp.push(node->right);
                }
            }
            q = temp;
        }
        return true;
    }
};