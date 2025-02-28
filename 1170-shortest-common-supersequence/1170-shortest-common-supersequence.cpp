class Solution {
    string shortestString(string longestCom, string str1, string str2) {
        string res = "";

        int index = 0;
        int len = longestCom.size();
        int n1 = str1.size(), n2 = str2.size();
        int i = 0, j = 0;

        while (index < len) {
           while(str1[i] != longestCom[index]){
                res.push_back(str1[i++]);
           }

           while(str2[j] != longestCom[index]){
                res.push_back(str2[j++]);
           }

            res.push_back(longestCom[index++]);
            i++;
            j++;
        }

        while(i < n1){
            res.push_back(str1[i++]);
        }
        while(j < n2){
            res.push_back(str2[j++]);
        }

        return res;
    }

    string longestCommon(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));

        for (int i = 0; i <= n1; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= n2; i++) {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        string longestCom = "";
        while (n1 > 0 && n2 > 0) {
            if (str1[n1 - 1] == str2[n2 - 1]) {
                longestCom.push_back(str1[n1 - 1]);
                n1--;
                n2--;
            } else {
                if (dp[n1][n2] == dp[n1 - 1][n2]) {
                    n1--;
                } else {
                    n2--;
                }
            }
        }

        reverse(longestCom.begin(), longestCom.end());
        return longestCom;
    }

public:
    string shortestCommonSupersequence(string str1, string str2) {

        string longestCom = longestCommon(str1, str2);
        string shortestCom = shortestString(longestCom, str1, str2);

        return shortestCom;
    }
};