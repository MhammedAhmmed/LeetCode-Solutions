class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        int n = nums.size();
        int l1 = 0, l2 = 0;

        int res = 1;
        unordered_map<int, int> freq;
        while(l2 < n){
            freq[nums[l2]]++;

            while(freq[nums[l2]] > k){
                freq[nums[l1++]]--;
            }
            res = max(res, l2 - l1 + 1);
            l2++;
        }
        return res;
        
    }
};