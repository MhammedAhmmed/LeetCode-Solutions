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
    int maxPathRes = INT_MIN;
    int minVal = -10000;
    int maxPath(TreeNode* root) {
        if (root == nullptr) {
            return minVal;
        }

        int leftPath = maxPath(root->left);
        int rightPath = maxPath(root->right);

        int maxPathThroughNode =
            max(root->val, max(root->val + leftPath, root->val + rightPath));

        maxPathRes = max(maxPathRes, max(maxPathThroughNode,
                                         root->val + leftPath + rightPath));
        return maxPathThroughNode;
    }

public:
    int maxPathSum(TreeNode* root) {
        maxPath(root);
        return maxPathRes;
    }
};