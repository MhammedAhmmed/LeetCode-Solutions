class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int maxValue = 1000;

        vector<int> freq(maxValue + 1, 0);

        for (auto num : nums) {
            for (int x : num) {
                freq[x]++;
            }
        }

        vector<int> res;
        int n = nums.size();

        for (int i = 1; i <= 1000; i++) {
            if (freq[i] == n) {
                res.push_back(i);
            }
        }

        return res;
    }
};