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
    TreeNode* constructTree(vector<int>& preorder, vector<int>& postorder, int lp, int rp, int ls, int rs){
        if(lp > rp || ls > rs){
            return nullptr;
        }

        TreeNode* node = new TreeNode(preorder[lp]);

        unordered_map<int,int>dist;
        int countDist = 0;

        int len = rp - lp;
        for(int i = 1; i <= len; i++){

            dist[preorder[lp + i]]++;
            if(dist[preorder[lp + i]]){
                countDist++;       
            }else{
                countDist--;       
            }
            
            dist[postorder[ls + i - 1]]--;
            if(dist[postorder[ls + i - 1]]){
                countDist++;       
            }else{
                countDist--;       
            }

            if(countDist == 0){
                node->left = constructTree(preorder, postorder, lp + 1, lp + i, ls, ls + i - 1);
                node->right = constructTree(preorder, postorder, lp + i + 1, rp, ls + i, rs - 1);

                break;
            }
        }

        return node;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
           return constructTree(preorder, postorder, 0, preorder.size() - 1, 0, preorder.size() - 1);
    }
};