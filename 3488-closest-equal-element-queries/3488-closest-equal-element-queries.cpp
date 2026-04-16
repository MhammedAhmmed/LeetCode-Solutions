class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>>mp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }
        
        vector<int>res(queries.size());
        for(int i = 0; i < queries.size(); i++){
            if(mp[nums[queries[i]]].size() == 1){
                res[i] = -1;
                continue;
            }
            int l = 0, r = mp[nums[queries[i]]].size() - 1;
            int mid;
            while(l <= r){
                mid = (l + r) / 2;
                if(mp[nums[queries[i]]][mid] == queries[i]){
                    break;
                }
                if(mp[nums[queries[i]]][mid] < queries[i]){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
            int left, right;
            if(mid == 0){
                left = mp[nums[queries[i]]].size() - 1;
            }else{
                left = mid - 1;
            }
            if(mid == mp[nums[queries[i]]].size() - 1){
                right = 0;
            }else{
                right = mid + 1;
            }
            int minLeft = min(abs(mp[nums[queries[i]]][left] - mp[nums[queries[i]]][mid]), n - abs(mp[nums[queries[i]]][left] - mp[nums[queries[i]]][mid]));
            int minRight = min(abs(mp[nums[queries[i]]][right] - mp[nums[queries[i]]][mid]), n - abs(mp[nums[queries[i]]][right] - mp[nums[queries[i]]][mid]));

            res[i] = min(minLeft, minRight);
        }
        return res;
    }
};