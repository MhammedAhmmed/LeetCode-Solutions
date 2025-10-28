class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int sum = 0;
        for(int x : nums){
            sum += x;
        }

        int n = nums.size();
        int currSum = 0;
        int res = 0;
        for(int i = 0 ; i < n; i++){
            if(nums[i] == 0){
                if(currSum == (sum - currSum)){
                    res += 2;
                }else if(abs(currSum - (sum - currSum)) == 1){
                    res++;
                }
            }
            currSum += nums[i];
        }
        return res;
    }
};