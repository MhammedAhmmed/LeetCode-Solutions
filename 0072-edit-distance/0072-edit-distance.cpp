class Solution {
    int editDistance(string word1, string word2, vector<vector<int>>& dp,
                     int p1, int p2) {
        if (p1 < 0) {
            return (p2 - 0 + 1);
        }
        if (p2 < 0) {
            return (p1 - 0 + 1);
        }

        if (dp[p1][p2] != -1) {
            return dp[p1][p2];
        }

        if (word1[p1] == word2[p2]) {
            return dp[p1][p2] = editDistance(word1, word2, dp, p1 - 1, p2 - 1);
        }

        int insertCost = 1 + editDistance(word1, word2, dp, p1, p2 - 1);
        int deleteCost = 1 + editDistance(word1, word2, dp, p1 - 1, p2);
        int replaceCost = 1 + editDistance(word1, word2, dp, p1 - 1, p2 - 1);

        int res = min(insertCost, min(deleteCost, replaceCost));

        return dp[p1][p2] = res;
    }

public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        vector<vector<int>> dp(n1, vector<int>(n2, -1));

        return editDistance(word1, word2, dp, n1 - 1, n2 - 1);
    }
};