class Solution {
    bool prefixAndSuffix(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();

        if (n2 > n1) {
            return false;
        }
        bool prefix = true, suffix = true;
        for (int i = 0; i < n2; i++) {
            if (s1[i] != s2[i]) {
                prefix = false;
                break;
            }
        }
        for (int i = 0; i < n2; i++) {
            if (s1[n1 - i - 1] != s2[n2 - i - 1]) {
                suffix = false;
                break;
            }
        }

        return prefix && suffix;
    }

public:
    int countPrefixSuffixPairs(vector<string>& words) {

        int n = words.size();

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (prefixAndSuffix(words[j], words[i])) {
                    res++;
                }
            }
        }

        return res;
    }
};