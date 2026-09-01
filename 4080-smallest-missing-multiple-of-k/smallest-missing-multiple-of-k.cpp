class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());
        int res = k;

        int i = 0;
        while(i < nums.size()){
            if(nums[i] < res){
                i++;
            }else if (nums[i] == res){
                res += k;
                i++;
            }else{
                return res;
            }
        }
        return res;
    }
};