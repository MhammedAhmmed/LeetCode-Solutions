class Solution {
    bool vowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        int n = words.size();

        vector<int> pref(n, 0);
        for (int i = 0; i < n; i++) {
            string word = words[i];
            if (vowel(word[0]) && vowel(word[word.size() - 1])) {
                pref[i]++;
            }
        }
        for (int i = 1; i < n; i++) {
            pref[i] += pref[i - 1];
        }

        int len = queries.size();
        vector<int> res(len, 0);
        for (int i = 0; i < len; i++) {
            int s = queries[i][0], e = queries[i][1];
            if (s == 0) {
                res[i] = pref[e];
            } else {
                res[i] = pref[e] - pref[s - 1];
            }
        }
        return res;
    }
};