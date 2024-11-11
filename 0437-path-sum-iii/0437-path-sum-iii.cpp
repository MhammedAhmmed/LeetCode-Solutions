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
    int countTargetsum(vector<pair<int, bool>>& branch, int targetSum) {
        int n = branch.size();

        map<long long, int> mp;
        mp[0]++;

        long long sum = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            sum += branch[i].first;

            long long need = sum - targetSum;

            if (mp[need] && branch[i].second) {
                branch[i].second = false;

                res += mp[need];
            }

            mp[sum]++;
        }

        return res;
    }

public:
    vector<pair<int, bool>> branchNode;

    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return 0;
        }
        branchNode.push_back({root->val, true});

        int res = 0;
        if (root->left == nullptr && root->right == nullptr) {
            res += countTargetsum(branchNode, targetSum);
            cout << root->val << " " << res << endl;
        }

        res += pathSum(root->left, targetSum);
        res += pathSum(root->right, targetSum);

        branchNode.pop_back();

        return res;
    }
};
