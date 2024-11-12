class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        sort(items.begin(), items.end());

        int n = items.size();

        for (int i = 1; i < n; i++) {
            items[i][1] = max(items[i][1], items[i - 1][1]);
        }

        int qn = queries.size();
        vector<int> res(qn, 0);

        for (int i = 0; i < qn; i++) {
            auto it = upper_bound(
                items.begin(), items.end(), vector<int>{queries[i], INT_MAX},
                [](const vector<int>& a, const vector<int>& b) {
                    return a[0] < b[0];
                });

            if (it != items.begin()) {
                it--;
                res[i] = it->at(1);
            }
        }

        return res;
    }
};