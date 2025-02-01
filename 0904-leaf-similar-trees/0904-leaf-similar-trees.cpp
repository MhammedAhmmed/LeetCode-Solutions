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
    void getLeaves(TreeNode* root, vector<int>&leaves){
        if(root == nullptr){
            return;
        }

        if(root->left == nullptr && root->right == nullptr){
            leaves.push_back(root->val);
        }

        getLeaves(root->left, leaves);
        getLeaves(root->right, leaves);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>leaves1, leaves2;

        getLeaves(root1, leaves1);
        getLeaves(root2, leaves2);
        

        if(leaves1.size() != leaves2.size()){
            return false;
        }

        int n = leaves1.size();
        for(int i = 0; i < n; i++){
            if(leaves1[i] != leaves2[i]){
                return false;
            }
        }

        return true;
    }
};