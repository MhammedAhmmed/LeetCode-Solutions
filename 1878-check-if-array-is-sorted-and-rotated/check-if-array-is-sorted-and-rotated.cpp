class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            bool rot = true;
            for(int j = i + 1; j < i + n; j++){
                if(nums[j % n] < nums[(j - 1) % n]){
                    rot = false;
                    break;
                }
            }
            if(rot){
                return true;
            }
        }
        return false;
    }
};