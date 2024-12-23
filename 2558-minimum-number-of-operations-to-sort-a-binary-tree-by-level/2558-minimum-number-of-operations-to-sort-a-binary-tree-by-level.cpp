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
	int minimumOperations(TreeNode* root) {
		queue<TreeNode*>q;
		q.push(root);

		int res = 0;

		while (!q.empty()) {

			int n = q.size();
			vector<int>v(n);
			vector<int>temp(n);
			unordered_map<int, int>mp;

			int i = 0;
			int x = n;
			while (x--) {
				TreeNode* top = q.front();
				q.pop();

				v[i] = top->val;
				temp[i++] = top->val;

				if (top->left != nullptr) {
					q.push(top->left);
				}
				if (top->right!= nullptr) {
					q.push(top->right);
				}
			}

			sort(temp.begin(), temp.end());

			for (int i = 0; i < n; i++) {
				mp[v[i]] = i;
			}

			for (int i = 0; i < n; i++) {
				if (v[i] != temp[i]) {
					int index = mp[temp[i]];

					int val = v[index];
					v[index] = v[i];
					v[i] = val;

					mp[v[i]] = i;
					mp[v[index]] = index;
					res++;
				}
			}
		}
		return res;
	}
};