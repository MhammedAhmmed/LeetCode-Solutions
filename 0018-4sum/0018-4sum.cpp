class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>>res;

        for(int i = 0; i < n - 3; i++){
            if(i != 0 && (nums[i] == nums[i - 1])){
                continue;
            }
            for(int j = i + 1; j < n - 2; j++){
                if(j != i + 1 && (nums[j] == nums[j - 1])){
                    continue;
                }

                int prev = INT_MAX;
                int p1 = j + 1, p2 = n - 1;
                while(p1 < p2){
                    if((long long)nums[i] + nums[j] + nums[p1] + nums[p2] > target){
                        p2--;
                    }
                    else if((long long)nums[i] + nums[j] + nums[p1] + nums[p2] < target){
                        p1++;
                    }
                    else{
                        if(nums[p1] != prev){
                            res.push_back({nums[i], nums[j], nums[p1], nums[p2]});
                            prev = nums[p1];
                        }
                        p1++;
                        p2--;
                    }
                }
            }
        }
        return res;
    }
};