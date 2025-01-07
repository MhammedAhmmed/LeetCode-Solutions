class Solution {
    bool substring(string s, string t) {
        int sn = s.size(), tn = t.size();

        for (int i = 0; i <= sn - tn; i++) {
            bool sub = true;

            for (int j = 0; j < tn; j++) {
                if (t[j] != s[i + j]) {
                    sub = false;
                    break;
                }
            }

            if (sub) {
                return true;
            }
        }

        return false;
    }

public:
    vector<string> stringMatching(vector<string>& words) {

        int n = words.size();

        vector<string> res;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }

                if (substring(words[j], words[i])) {
                    res.push_back(words[i]);
                    break;
                }
            }
        }

        return res;
    }
};