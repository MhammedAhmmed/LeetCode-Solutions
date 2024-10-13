class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();

        vector<int> pointers(n, 0);

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        int left = nums[0][0], right = nums[0][0];
        for (int i = 0; i < n; i++) {
            left = min(left, nums[i][0]);
            right = max(right, nums[i][0]);

            pq.push({nums[i][0], {i, 0}});
        }

        vector<int> res{left, right};

        while (true) {
            int val = pq.top().first;
            int arrNum = pq.top().second.first;
            int index = pq.top().second.second;

            pq.pop();
            index++;
            if (index >= nums[arrNum].size()) {
                break;
            }

            pq.push({nums[arrNum][index], {arrNum, index}});

            right = max(right, nums[arrNum][index]);
            left = pq.top().first;

            if (right - left < res[1] - res[0]) {
                res = {left, right};
            }
        }

        return res;
    }
};