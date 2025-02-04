class Solution {
public:
    bool same(unordered_map<string, int>& mp1,
              unordered_map<string, int>& mp2) {

        for (auto entry : mp1) {
            if (mp1[entry.first] != mp2[entry.first]) {
                return false;
            }
        }

        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words.size();
        int len = words[0].size();

        int wordsLen = len * n;

        int vLen = s.size() - wordsLen;

        unordered_map<string, int> freq;
        for (string str : words) {
            freq[str]++;
        }

        vector<int> res;
        for (int i = 0; i <= vLen; i++) {
            unordered_map<string, int> mp;
            for (int j = i; j < i + wordsLen; j++) {
                mp[s.substr(j, len)]++;
                j += len - 1;
            }

            if (same(freq, mp)) {
                res.push_back(i);
            }
        }

        return res;
    }
};