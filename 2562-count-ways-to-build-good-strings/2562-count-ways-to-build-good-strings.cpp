class Solution {
    int mod = 1e9 + 7;
    int countStrings(int low, int high, int zero, int one, int stringLen,
                     vector<int>& dp) {
        if (stringLen > high) {
            return 0;
        }

        if (dp[stringLen] != -1) {
            return dp[stringLen];
        }
        long long res = 0;

        res += countStrings(low, high, zero, one, stringLen + zero, dp);
        res %= mod;

        res += countStrings(low, high, zero, one, stringLen + one, dp);
        res %= mod;

        if (stringLen >= low) {
            res++;
        }

        return dp[stringLen] = res % mod;
    }

public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);
        return countStrings(low, high, zero, one, 0, dp);
    }
};