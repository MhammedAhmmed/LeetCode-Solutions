class Solution {
public:
    int numTilings(int n) {
        if (n <= 2) {
            return n;
        }

        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;
        dp[2] = 2;

        int mod = 1e9 + 7;
        for (int i = 3; i <= n; i++) {
            dp[i] = (((2 * dp[i - 1]) % mod) + (dp[i - 3] % mod)) % mod;
        }

        return dp[n];
    }
};