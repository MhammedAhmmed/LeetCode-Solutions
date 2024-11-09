/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
	void preOrderTraversal(TreeNode* root, vector<int>& values) {
		if (root == NULL)
			return;

		values.push_back(root->val);

		preOrderTraversal(root->left, values);
		preOrderTraversal(root->right, values);
	}
public:
	void flatten(TreeNode* root) {
		vector<int>values;
		preOrderTraversal(root, values);

		int n = values.size();

		TreeNode* temp = root;
		for (int i = 0; i < n; i++) {
			temp->val = values[i];
			temp->left = nullptr;

			if (i != n - 1 && temp->right == nullptr) {
				temp->right = new TreeNode();
			}

			temp = temp->right;
		}
	}
};