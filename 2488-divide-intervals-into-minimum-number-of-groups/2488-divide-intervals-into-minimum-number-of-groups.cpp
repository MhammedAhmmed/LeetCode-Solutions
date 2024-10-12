class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int maxSize = 1000000;

        vector<int> v(maxSize + 2, 0);

        for (auto interval : intervals) {
            v[interval[0]]++;
            v[interval[1] + 1]--;
        }

        for (int i = 1; i <= maxSize + 1; i++) {
            v[i] += v[i - 1];
        }
        return *max_element(v.begin(), v.end());
    }
};