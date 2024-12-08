class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();

        sort(events.begin(), events.end());

        vector<int> rightProfit(n);
        rightProfit[n - 1] = events[n - 1][2];
        for (int i = n - 2; i >= 0; i--) {
            rightProfit[i] = max(rightProfit[i + 1], events[i][2]);
        }

        int maxProfit = 0;
        for (int i = 0; i < n; i++) {
            int l = i + 1, r = n - 1, mid;
            int maxIntervalProfit = 0;
            while (l <= r) {
                mid = (l + r) / 2;

                if (events[mid][0] > events[i][1]) {
                    maxIntervalProfit = rightProfit[mid];
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            maxProfit = max(maxProfit, events[i][2] + maxIntervalProfit);
        }

        return maxProfit;
    }
};