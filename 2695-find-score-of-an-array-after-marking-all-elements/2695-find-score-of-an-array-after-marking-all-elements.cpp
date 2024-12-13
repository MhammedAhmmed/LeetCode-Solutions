class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> marked(n, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        long long res = 0;

        while (!pq.empty()) {
            pair<int, int> minE = pq.top();
            pq.pop();

            if (marked[minE.second]) {
                continue;
            }

            res += minE.first;

            marked[minE.second] = 1;

            if (minE.second != 0) {
                marked[minE.second - 1] = 1;
            }
            if (minE.second != n - 1) {
                marked[minE.second + 1] = 1;
            }
        }

        return res;
    }
};