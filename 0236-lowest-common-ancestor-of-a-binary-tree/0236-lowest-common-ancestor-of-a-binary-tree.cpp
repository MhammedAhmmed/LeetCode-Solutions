/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool getPath(TreeNode* root, TreeNode* p, vector<char>& path) {
        if (root == NULL)
            return false;

        if (root == p)
            return true;

        path.push_back('L');
        if (getPath(root->left, p, path)) {
            return true;
        }
        path.pop_back();

        path.push_back('R');
        if (getPath(root->right, p, path))
            return true;
        path.pop_back();

        return false;
    }
    TreeNode* getNode(TreeNode* root, queue<char>& path) {
        if (path.empty())
            return root;

        if (path.front() == 'L') {
            path.pop();
            return getNode(root->left, path);
        } else {
            path.pop();
            return getNode(root->right, path);
        }
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<char> pPath, qPath;

        getPath(root, p, pPath);
        getPath(root, q, qPath);

        queue<char> commonPath;
        int commonMaxLen = min(pPath.size(), qPath.size());

        for (int i = 0; i < commonMaxLen; i++) {
            if (pPath[i] != qPath[i])
                break;

            commonPath.push(pPath[i]);
        }

        return getNode(root, commonPath);
    }
};