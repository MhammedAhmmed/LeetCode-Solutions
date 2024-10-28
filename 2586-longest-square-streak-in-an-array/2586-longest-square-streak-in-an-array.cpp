class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end()) + 1;

        vector<bool> exist(maxNum, false);
        vector<bool> vis(maxNum, false);

        for (int num : nums) {
            exist[num] = 1;
        }

        int res = 0;

        for (int i = 2; i < maxNum; i++) {
            if (!vis[i] && exist[i]) {
                int count = 0;
                long long index = i;
                while (index < maxNum && exist[index]) {
                    count++;
                    vis[index] = true;
                    index = index * index;
                }
                res = max(res, count);
            }
        }

        if (res <= 1) {
            return -1;
        }
        return res;
    }
};