class Solution {
    vector<vector<int>> allCombination(int l, int r, int k) {
        if (k == 1) {
            vector<vector<int>> res(r - l + 1, vector<int>(1));

            for (int i = l; i <= r; i++) {
                res[i - l][0] = i;
            }

            return res;
        }

        vector<vector<int>> res;

        for (int i = l; i <= r; i++) {
            vector<vector<int>> next = allCombination(i + 1, r + 1, k - 1);

            for (vector<int> v : next) {
                v.push_back(i);
                res.push_back(v);
            }
        }

        return res;
    }

public:
    vector<vector<int>> combine(int n, int k) {
        return allCombination(1, n - k + 1, k);
    }
};