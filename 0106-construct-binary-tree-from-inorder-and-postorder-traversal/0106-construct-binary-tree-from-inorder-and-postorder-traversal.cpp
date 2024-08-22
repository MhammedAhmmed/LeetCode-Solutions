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
TreeNode* constructTree(vector<int>& inorder, vector<int>& postorder, int lIN, int rIN, int lPost, int RPost) {
    if (rIN < lIN || RPost < lPost)
        return NULL;

    TreeNode* node = new TreeNode(postorder[RPost], NULL, NULL);
    int rootIndex = 0;
    set<int>s;
    for (int i = lIN; i <= rIN; i++) {
        if (inorder[i] == postorder[RPost]) {
            rootIndex = i;
            break;
        }
        s.insert(inorder[i]);
    }
    int rightIndex = RPost;
    for (int i = lPost; i < RPost; i++) {
        if (s.find(postorder[i]) == s.end()) {
            rightIndex = i;
            break;
        }
    }
    node->left = constructTree(inorder, postorder, lIN, rootIndex - 1, lPost, rightIndex - 1);
    node->right = constructTree(inorder, postorder, rootIndex + 1, rIN, rightIndex, RPost - 1);

    return node;
}
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size() - 1;
        return constructTree(inorder, postorder, 0, n, 0, n);
    }
};