class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        unordered_map<int,int>freq;
        int n = nums.size();
        for(int i = 0; i <= n - k; i++){
            vector<bool>appear(51, false);
            for(int j = i; j < i + k; j++){
                appear[nums[j]] = 1;
            }
            for(int j = 0; j <= 50; j++){
                if(appear[j]){
                    freq[j]++;
                }
            }
        }
        int res = -1;
        for(auto entry : freq){
            if(entry.second == 1){
                res = max(res, entry.first);
            }
        }
        return res;
    }
};