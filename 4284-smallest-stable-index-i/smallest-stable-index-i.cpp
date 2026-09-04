class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            int maxE = nums[i], minE = nums[i];

            for(int l = 0; l <= i; l++){
                maxE = max(maxE, nums[l]);
            }

            for(int r = i; r < n; r++){
                minE = min(minE, nums[r]);
            }
            if((maxE - minE) <= k){
                return i;
            }
        }
        return -1;
    }
};