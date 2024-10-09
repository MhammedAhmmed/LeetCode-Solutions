class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int>>mp;

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        for (auto entry : mp) {
                int len = entry.second.size();

                for (int i = 0; i < len - 1; i++) {
                    if (entry.second[i + 1] - entry.second[i] <= k)
                        return true;
                }
        }
        return false;
    }
};