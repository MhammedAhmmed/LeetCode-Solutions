class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxE = *max_element(nums.begin(), nums.end());

        int res = 0;

        for(int i = 0; i < k; i++){
            res += (maxE + i);
        }

        return res;
    }
};