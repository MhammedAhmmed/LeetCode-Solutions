class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {

        int n = nums.size(), p = 0;
        int maxSum = 0;
        while(p < n){
            int sum = nums[p];
            p++;

            while(p < n && nums[p] > nums[p-1]){
                sum += nums[p++];
            }

            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};