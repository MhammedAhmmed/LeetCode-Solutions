class Solution {
    bool anagram(string str1, string str2) {
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        return str1 == str2;
    }

public:
    vector<string> removeAnagrams(vector<string>& words) {

        int n = words.size();
        vector<bool> deleted(n, false);
        int preIndex = 0;
        for (int i = 1; i < n; i++) {
            if (anagram(words[i - 1], words[i])) {
                deleted[i] = true;
            } else {
                preIndex = i;
            }
        }

        vector<string> res;
        for (int i = 0; i < n; i++) {
            if (!deleted[i]) {
                res.push_back(words[i]);
            }
        }
        return res;
    }
};