class Solution {
    int gcd(int a, int b){
        if(a % b == 0){
            return b;
        }
        return gcd(b, a % b);
    }
    bool product(int l, int r, vector<int>&nums){
        int gcdArr = gcd(nums[l], nums[l + 1]);
        int lcmArr = (nums[l] * nums[l + 1]) / gcdArr;
        unsigned long long prod = nums[l] * nums[l + 1];
        for(int i = l + 2; i <= r; i++){
            prod *= nums[i];
            
            gcdArr = gcd(nums[i], gcdArr);
            int tempGcd = gcd(nums[i], lcmArr);
            lcmArr = (lcmArr * nums[i]) / tempGcd;        
        }

        return prod == gcdArr * lcmArr;
    }
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 1;
        for(int l = 0; l < n - 1; l++){
            for(int r = l + 1; r < n; r++){
                if(product(l, r, nums)){
                    maxLen = max(maxLen, r - l + 1);
                }
            }
        }
        return maxLen;
    }
};