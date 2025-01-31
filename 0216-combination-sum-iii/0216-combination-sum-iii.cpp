class Solution {
public:
    void findCombinations(vector<int>& combination, vector<vector<int>>& res,
                          int start, int k, int n) {
        if (k == 0) {
            int sum = 0;
            for (int num : combination) {
                sum += num;
            }
            if (sum == n) {
                res.push_back(combination);
            }
            return;
        }

        if (start > 9) {
            return;
        }

        for (int i = start; i <= 9; i++) {
            combination.push_back(i);

            findCombinations(combination, res, i + 1, k - 1, n);

            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> combination;

        findCombinations(combination, res, 1, k, n);

        return res;
    }
};