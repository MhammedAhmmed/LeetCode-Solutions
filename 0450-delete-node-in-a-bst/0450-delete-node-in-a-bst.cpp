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
    TreeNode* getSmallestLeft(TreeNode* node) {
        if (node->left == nullptr) {
            return node;
        }

        return getSmallestLeft(node->left);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }

        if (root->val == key) {
            if (root->left == nullptr) {
                return root->right;
            }
            if (root->right == nullptr) {
                return root->left;
            }

            TreeNode* temp = getSmallestLeft(root->right);
            temp->left = root->left;

            return root->right;
        }

        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);

        return root;
    }
};