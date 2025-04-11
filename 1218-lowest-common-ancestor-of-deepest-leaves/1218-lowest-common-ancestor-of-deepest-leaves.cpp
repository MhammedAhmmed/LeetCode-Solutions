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

	unordered_map<int, pair<int, int>>childDepth;

	int leftRightDepth(TreeNode* node) {
		if (node == nullptr) {
			return 0;
		}

		childDepth[node->val] = { leftRightDepth(node->left) + 1 , leftRightDepth(node->right) + 1};

		return max(childDepth[node->val].first, childDepth[node->val].second);
	}

	TreeNode* lcaDeepest(TreeNode* root) {
		if (childDepth[root->val].first == childDepth[root->val].second) {
			return root;
		}
		if (childDepth[root->val].first > childDepth[root->val].second) {
			return lcaDeepest(root->left);
		}
		return lcaDeepest(root->right);
	}
public:
	TreeNode* lcaDeepestLeaves(TreeNode* root) {
		leftRightDepth(root);
		return lcaDeepest(root);
	}
};