class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        bool allZero = true;
        for(int num:  nums){
            if(num){
                allZero = false;
            }
        }
        if(allZero){
            return 0;
        }

        int nxor = 0;
        for(int num: nums){
            nxor ^= num;
        }
        if(nxor){
            return nums.size();
        }
        return nums.size() - 1;
    }
};