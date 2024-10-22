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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> levelSumRes;

        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            queue<TreeNode*> temp;

            long long levelSum = 0;

            while (!q.empty()) {
                TreeNode* node = q.front();
                q.pop();

                levelSum += node->val;

                if (node->left != NULL) {
                    temp.push(node->left);
                }

                if (node->right !=  NULL) {
                    temp.push(node->right);
                }
            }

            levelSumRes.push_back(levelSum);

            q = temp;
        }
        if (k > levelSumRes.size()) return -1;

        sort(levelSumRes.begin(), levelSumRes.end(), greater<long long>());

        return levelSumRes[k - 1];
    }
};