class Solution {
    static bool comparepair(pair<pair<int, int>, int>& a,
                     pair<pair<int, int>, int>& b) {
        return a.first.first < b.first.first;
    }
    bool consistent(pair<int, int> a, pair<int, int> b) {
        return !(a.first < b.second && b.first < a.second);
    }
    int nextConsistent(vector<pair<pair<int, int>, int>>& intervals, int l,
                       int r) {
        int index = -1;
        int prev = l - 1;
        int mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (consistent(intervals[prev].first, intervals[mid].first)) {
                index = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return index;
    }
    int jobSchedul(vector<pair<pair<int, int>, int>>& intervals, int n, int i,
                   vector<int>& dp) {
        if (i >= n) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int take = intervals[i].second, notTake = 0;
        int nextConsistentinexd = nextConsistent(intervals, i + 1, n - 1);

        if (nextConsistentinexd != -1) {
            take += jobSchedul(intervals, n, nextConsistentinexd, dp);
        }
        notTake = jobSchedul(intervals, n, i + 1, dp);

        return dp[i] = max(take, notTake);
    }

public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        int n = startTime.size();
        vector<pair<pair<int, int>, int>> intervals(n);

        for (int i = 0; i < n; i++) {
            intervals[i] = {{startTime[i], endTime[i]}, profit[i]};
        }

        sort(intervals.begin(), intervals.end(), comparepair);
        vector<int> dp(n, -1);
        jobSchedul(intervals, n, 0, dp);

        for (int i = 0; i < n; i++)
            cout << dp[i] << " ";

        return dp[0];
    }
};