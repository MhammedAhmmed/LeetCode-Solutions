class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int p = 0, n = nums.size();
        int p2 = 1;
        
        while(p2 < n){
            if(nums[p2] <= nums[p]){
                break;
            }
            p2++;
            p++;
        }
        if(p == 0 || p2 == n || nums[p] == nums[p2]){
            return false;
        }
        int q = p + 1;
        p2 = q + 1;
        while(p2 < n){
            if(nums[p2] >= nums[q]){
                break;
            }
            p2++;
            q++;
        }
        if(q >= n-1 || p2 == n || nums[q] == nums[p2]){
            return false;
        }
        cout << p2;
        while(p2 < n){
            if(nums[p2] <= nums[p2 - 1]){
                return false;
            }
            p2++;
        }

        return true;
    }
};