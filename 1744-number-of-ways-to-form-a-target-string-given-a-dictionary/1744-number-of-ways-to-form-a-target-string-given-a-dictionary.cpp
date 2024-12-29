
class Solution {


	int wLen;
	int tLen;
	string target;
	vector<vector<int>> freq;
	vector<vector<int>> dp;

	int mod = 1e9 + 7;
	int numOfWays(int wIndex, int tIndex) {
		if (tIndex >= tLen) {
			return 1;
		}
		if (wIndex >= wLen) {
			return 0;
		}
		if (dp[wIndex][tIndex] != -1) {
			return dp[wIndex][tIndex];
		}

		long long take = 0, notTake = 0;

		if (freq[target[tIndex] - 'a'][wIndex]) {
			take = numOfWays(wIndex + 1, tIndex + 1) % mod;
			take *= freq[target[tIndex] - 'a'][wIndex];
			take %= mod;
		}

		notTake = numOfWays(wIndex + 1, tIndex) % mod;

		return dp[wIndex][tIndex] = (take + notTake) % mod;
	}

public:
	int numWays(vector<string>& words, string target) {
		int wordLen = words[0].size();
		int targetLen = target.size();

		vector<vector<int>> freq(26, vector<int>(wordLen, 0));

		int n = words.size();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < wordLen; j++) {
				freq[words[i][j] - 'a'][j]++;
			}
		}
		words.clear();

		vector<vector<int>> dp(wordLen, vector<int>(targetLen, -1));
		this->dp = dp;
		this->freq = freq;
		this->target = target;
		this->tLen = targetLen;
		this->wLen = wordLen;

		return numOfWays(0, 0);
	}
};