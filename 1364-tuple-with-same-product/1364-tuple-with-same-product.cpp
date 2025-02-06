class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>freq;

        int n = nums.size();

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                freq[nums[i] * nums[j]]++;
            }
        }

        int res = 0;
        for(auto entry: freq){
            int x = entry.second;
            res += (x * (x - 1)) * 4;
        }
        
        return res;
    }
};