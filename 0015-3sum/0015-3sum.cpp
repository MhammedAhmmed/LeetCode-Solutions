class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int p = 0, n = nums.size();

        vector<vector<int>>res;
        vector<int>temp(3);

        while(p < n - 2){
            temp[0] = nums[p];

            int l = p + 1, r = n - 1;
            int prel = nums[p] - 1;

            while(l < r){
                if(nums[p] + nums[l] + nums[r] > 0){
                    r--;
                }
                else if(nums[p] + nums[l] + nums[r] < 0){
                    l++;
                }
                else{
                    if(nums[l] != prel){
                        prel = nums[l];

                        temp[1] = nums[l];
                        temp[2] = nums[r];
                        res.push_back(temp);
                    }
                    l++;
                    r--;
                }
            }

            p++;
            while(p < n && nums[p] == nums[p - 1]){
                p++;
            }
        }
        
        return res;
    }
};