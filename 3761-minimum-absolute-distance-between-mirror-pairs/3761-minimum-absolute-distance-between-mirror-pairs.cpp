class Solution {
public:
    int reverseInt(int x){
        string str = to_string(x);
        reverse(str.begin(), str.end());
        return stoi(str);
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>>mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }

        int res = n;
        bool exist = false;
        for(int i = 0; i < n; i++){
            int reverseX = reverseInt(nums[i]);
            if(mp.find(reverseX) == mp.end()){
                continue;
            }

            auto upper = upper_bound(mp[reverseX].begin(), mp[reverseX].end(), i);
            if(upper != mp[reverseX].end()){
                exist = true;
                res = min(res, abs(i - *upper));
            }
        }

        return exist? res : -1;
    }
};