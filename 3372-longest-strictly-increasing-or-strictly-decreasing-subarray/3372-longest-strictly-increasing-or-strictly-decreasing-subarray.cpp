class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int p1 = 0, p2 = 0, n = nums.size();

        int res = 1;

        while(p1 < n){
            if(p2 == n - 1){
                break;
            }

            if(nums[p2 + 1] == nums[p2]){
                p1++;
                p2++;
            }
            else if(nums[p2] > nums[p2 + 1]){
                while(p2 + 1 < n && nums[p2] > nums[p2 + 1]){
                    p2++;
                }
            }
            else{
                while(p2 + 1 < n && nums[p2] < nums[p2 + 1]){
                    p2++;
                }
            }

            res = max(res, p2 - p1 + 1);
            p1 = p2;
        }
        
        return res;
    }
};