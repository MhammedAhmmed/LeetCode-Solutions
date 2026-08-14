class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxE = *max_element(nums.begin(), nums.end());
        int minE = *min_element(nums.begin(), nums.end());
        vector<bool>exist(maxE - minE + 1, false);
        for(int i = 0; i < nums.size(); i++){
            exist[nums[i] - minE] = 1;
        }
        vector<int>res;
        for(int i = minE; i <= maxE; i++){
            if(!exist[i - minE]){
                res.push_back(i);
            }
        }
        
        
        return res;        
    }
};