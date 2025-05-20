class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>>res;

        for(int i = 0; i < n - 2; i++){
            if(i != 0 && (nums[i] == nums[i - 1])){
                continue;
            }

            int p1 = i + 1, p2 = n - 1;
            int prev = INT_MAX;

            while(p1 < p2){
                if(nums[i] + nums[p1] + nums[p2] > 0){
                    p2--;
                }else if(nums[i] + nums[p1] + nums[p2] < 0){
                    p1++;
                }else{
                    if(nums[p1] != prev){
                        res.push_back({nums[i], nums[p1], nums[p2]});
                        prev = nums[p1];
                    }
                    p1++;
                    p2--;
                }
            }
        }
        return res;
    }
};