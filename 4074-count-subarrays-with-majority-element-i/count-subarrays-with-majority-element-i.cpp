class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        int res = 0;
        vector<int>freq(n);
        int targetFreq = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == target){
                targetFreq++;
            }
            freq[i] = targetFreq;
            if(targetFreq > (i + 1) / 2){
                res++;
            }
        }

        for(int i = 1 ;i < n; i++){
            if(nums[i - 1] == target){
                for(int j = i ;j < n; j++){
                    freq[j]--;
                }
            }
            for(int j = i; j < n; j++){
                if(freq[j] > (j - i + 1) / 2){
                    res++;
                }
            }
        }
        return res;
    }
};