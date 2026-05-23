class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int minElement = nums[0];
        int pos = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] < minElement){
                minElement = nums[i];
                pos = i;
            }
            else if(minElement == nums[i]){
                if(nums[i - 1] > nums[i]){
                    pos = i;
                }
            }
        }
        for(int i = pos + 1; i < pos + n; i++){
            if(nums[i % n] < nums[(i - 1) % n]){
                return false;
            }
        }
        return true;
    }
};