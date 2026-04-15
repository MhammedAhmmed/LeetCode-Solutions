class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n);

        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                int ind = (i + nums[i]) % n;
                res[i] = nums[ind];
            }else if(nums[i] < 0){
                int ind = ((i + nums[i])%n + n) % n;
                res[i] = nums[ind];
            }else{
                res[i] = nums[i];
            }
        }
        return res;
    }
};