class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = n - 1;
        for(int i = n - 1; i > 0; i--){
            int l = 0, r = i - 1;
            int mid;

            while(l <= r){
                mid = (l + r) / 2;
                if(((long long)nums[mid] * k) < nums[i]){
                    l = mid + 1;
                }else{
                    int rem = (n - i - 1) + mid;
                    res = min(res, rem);
                    r = mid - 1;
                }
            }
        }
        return res;
    }
};