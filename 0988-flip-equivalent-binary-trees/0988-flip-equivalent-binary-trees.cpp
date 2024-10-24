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
    bool nodeEqual(TreeNode* node1, TreeNode* node2) {
        if (node1 == NULL && node2 != NULL || node1 != NULL && node2 == NULL)
            return false;

        return node1 == NULL && node2 == NULL || node1->val == node2->val;
    }

public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL)
            return true;

        if (!nodeEqual(root1, root2)) {
            return false;
        }

        if (nodeEqual(root1->left, root2->left) &&
            nodeEqual(root1->right, root2->right)) {
            return flipEquiv(root1->left, root2->left) &&
                   flipEquiv(root1->right, root2->right);
        }

        return flipEquiv(root1->left, root2->right) &&
               flipEquiv(root1->right, root2->left);
    }
};