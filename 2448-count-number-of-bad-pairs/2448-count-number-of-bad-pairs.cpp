class Solution {
public:
    long long countBadPairs(vector<int>& nums) {

        long long res = 0;
        int n = nums.size();
        unordered_map<int,int>freq;

        for(int i = 0; i < n; i++){
            res += (i - freq[i - nums[i]]);
            freq[i - nums[i]]++;
        }

        return res;
    }
};