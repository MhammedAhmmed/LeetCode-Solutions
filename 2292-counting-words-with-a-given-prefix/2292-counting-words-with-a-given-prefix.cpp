class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();

        int res = 0;
        int prefLen = pref.length();

        for (string word : words) {
            if (word.length() < prefLen) {
                continue;
            }

            bool prefix = true;

            for (int i = 0; i < prefLen; i++) {
                if (word[i] != pref[i]) {
                    prefix = false;
                    break;
                }
            }

            if (prefix) {
                res++;
            }
        }

        return res;
    }
};