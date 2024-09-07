class Solution {
    bool findWords(string s, int n, int index, vector<int>& dp, unordered_map<string, int>& mp) {
	if (index >= n)
		return true;

	if (dp[index] != -1)
		return dp[index] == 1;

	int findWord = 0;
    int len = min(20, n - index);

	for (int i = 1; i <= len; i++) {
		string temp = s.substr(index, i);
		if (mp[temp]) {
			if (findWords(s, n, index + i, dp, mp)) {
				findWord = 1;
				break;
			}
		}
	}
	dp[index] = findWord;
	return findWord == 1;
}
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int>mp;
        for (string s : wordDict) {
            mp[s]++;
        }
        int n = s.size();
        vector<int>dp(n, -1);
        findWords(s, n, 0, dp, mp);

        return dp[0] == 1;
    }
};