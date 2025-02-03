class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int>res;

        for(int i = 1; i < n; i++){
            if(nums[i] - nums[i - 1] == 0){
                continue;
            }

            if(res.empty()){
                res.push_back(nums[i] - nums[i - 1]);
            }
            else{
                if(nums[i] - nums[i - 1] > 0){
                    if(res[res.size() - 1] < 0){
                        res.push_back(nums[i] - nums[i - 1]);
                    }
                }
                else{
                    if(res[res.size() - 1] > 0){
                        res.push_back(nums[i] - nums[i - 1]);
                    }
                }
            }
        }

        return res.size() + 1;
    }
};