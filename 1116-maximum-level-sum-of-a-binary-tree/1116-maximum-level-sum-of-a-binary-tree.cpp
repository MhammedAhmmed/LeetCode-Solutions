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
    int maxLevelSum(TreeNode* root) {

        int maxVal = root->val;
        int x = 1;

        queue<TreeNode*>q;
        q.push(root);
        int level = 1;
        while(!q.empty()){
            int len = q.size();
            int levelSum = 0;
            while(len--){
                TreeNode* temp = q.front();
                q.pop();

                levelSum += temp->val;

                if(temp->left != nullptr){
                    q.push(temp->left);
                }   
                if(temp->right != nullptr){
                    q.push(temp->right);
                }   
            }

            if(levelSum > maxVal){
                maxVal = levelSum;
                x = level;
            }

            level++;
        }

        return x;
    }
};