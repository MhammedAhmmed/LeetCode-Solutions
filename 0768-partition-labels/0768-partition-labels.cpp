class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>freq(26, 0);

        for (char ch : s)
            freq[ch - 'a']++;

        vector<int>res;
        int n = s.size();
        int num = 0, intervalLen = 0;
        vector<bool>vis(26, false);
        for (int j = 0; j < n; j++) {
            intervalLen++;
            if (!vis[s[j] - 'a']) {
                vis[s[j] - 'a'] = 1;
                num += (freq[s[j] - 'a'] - 1);
            }
            else {
                num--;
            }
            if (num == 0 || j == n - 1) {
                res.push_back(intervalLen);
                intervalLen = 0;
            }
        }

        return res;
    }
};