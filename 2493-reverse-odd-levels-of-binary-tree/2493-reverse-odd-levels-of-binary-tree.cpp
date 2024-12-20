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
public:
	TreeNode* reverseOddLevels(TreeNode* root) {
		queue<TreeNode*>q;
		q.push(root);


		int level = 0;
		while (!q.empty()) {
			vector<int>values;
			int p;

			if (level & 1) {
				int n = q.size();
				p = n - 1;
				while (n--) {
					values.push_back(q.front()->val);
					q.push(q.front());
					q.pop();
				}
			}

			queue<TreeNode*>temp;
			
			while (!q.empty()) {
				if (level & 1) {
					q.front()->val = values[p--];
				}

				TreeNode* top = q.front();
				q.pop();

				if (top->left != nullptr) {
					temp.push(top->left);
					temp.push(top->right);
				}
			}

			level++;
			q = temp;
		}

		return root;

	}
};