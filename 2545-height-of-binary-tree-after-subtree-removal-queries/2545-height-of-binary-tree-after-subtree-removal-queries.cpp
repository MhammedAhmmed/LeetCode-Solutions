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
    int numOfNode(TreeNode* root) {
        if (root == NULL)
            return 0;

        return 1 + numOfNode(root->left) + numOfNode(root->right);
    }

    void initiateTree(TreeNode* root, vector<int>& parent, vector<int>& left,
                      vector<int>& right) {
        if (root == NULL) {
            return;
        }

        if (root->left != NULL) {
            parent[root->left->val] = root->val;
            left[root->val] = root->left->val;

            initiateTree(root->left, parent, left, right);
        }

        if (root->right != NULL) {
            parent[root->right->val] = root->val;
            right[root->val] = root->right->val;

            initiateTree(root->right, parent, left, right);
        }
    }
    int initiateDepth(TreeNode* root, vector<int>& depth) {
        if (root == NULL)
            return 0;

        int leftDepth = initiateDepth(root->left, depth);
        int rightDepth = initiateDepth(root->right, depth);

        depth[root->val] = max(leftDepth, rightDepth);

        return depth[root->val] + 1;
    }

public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {

        int n = numOfNode(root);

        vector<int> parent(n + 1);
        vector<int> depth(n + 1, 0);
        vector<int> leftChild(n + 1, -1);
        vector<int> rightChild(n + 1, -1);

        parent[root->val] = -1;

        initiateDepth(root, depth);
        initiateTree(root, parent, leftChild, rightChild);

        vector<int> res;

        for (int query : queries) {
            int node = parent[query];
            int h = 0;
            if (leftChild[node] == query) {
                if (rightChild[node] != -1)
                    h = depth[rightChild[node]] + 1;
            } else {
                if (leftChild[node] != -1)
                    h = depth[leftChild[node]] + 1;
            }

            while (node != root->val) {
                int pNode = parent[node];

                if (leftChild[pNode] == node) {
                    if (rightChild[pNode] != -1)
                        h = max(depth[rightChild[pNode]], h) + 1;
                    else
                        h++;
                } else {
                    if (leftChild[pNode] != -1)
                        h = max(depth[leftChild[pNode]], h) + 1;
                    else
                        h++;
                }

                node = pNode;
            }

            res.push_back(h);
        }

        return res;
    }
};