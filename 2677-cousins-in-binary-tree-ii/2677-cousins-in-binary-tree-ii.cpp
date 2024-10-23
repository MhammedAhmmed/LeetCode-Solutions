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
    TreeNode* replaceValueInTree(TreeNode* root) {

        root->val = 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            int childernSum = 0;

            while (n--) {
                TreeNode* node = q.front();
                q.pop();
                q.push(node);

                if (node->left != NULL) {
                    childernSum += node->left->val;
                }
                if (node->right != NULL) {
                    childernSum += node->right->val;
                }
            }
            queue<TreeNode*> temp;

            while (!q.empty()) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left != NULL && node->right != NULL) {
                    int leftVal = node->left->val;
                    int rightVal = node->right->val;

                    node->left->val = childernSum - leftVal - rightVal;
                    node->right->val = childernSum - leftVal - rightVal;

                    temp.push(node->left);
                    temp.push(node->right);
                }

                else if (node->left != NULL) {
                    node->left->val = childernSum - node->left->val;
                    temp.push(node->left);
                }

                else if (node->right != NULL) {
                    node->right->val = childernSum - node->right->val;
                    temp.push(node->right);
                }
            }

            q = temp;
        }

        return root;
    }
};