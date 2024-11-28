/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *right;
 *     TreeNode *left;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    int maxLen = 0;
    void zigZag(TreeNode* root, bool left, bool right, int zigzagLen) {
        if (root == nullptr) {
            return;
        }

        maxLen = max(maxLen, zigzagLen);

        if (left) {
            zigZag(root->left, false, true, zigzagLen + 1);
            zigZag(root->right, true, false, 1);
        } else {
            zigZag(root->right, true, false, zigzagLen + 1);
            zigZag(root->left, false, true, 1);
        }
    }

public:
    int longestZigZag(TreeNode* root) {
        zigZag(root->left, false, true, 1);
        zigZag(root->right, true, false, 1);
        return maxLen;
    }
};