class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int> freq;

        int p1 = 0, p2 = 0, n = s.size();

        while (p2 < n) {
            p1 = p2;

            string temp = "";
            while (p2 < n && s[p2] == s[p1]) {
                temp.push_back(s[p2]);
                p2++;
            }

            freq[temp]++;

            if (temp.size() > 1) {
                temp.pop_back();
                freq[temp] += 2;
            }

            if (temp.size() > 1) {
                temp.pop_back();
                freq[temp] += 3;
            }
        }

        int maxLength = -1;

        for (auto entry : freq) {
            if (entry.second >= 3) {
                int strLen = entry.first.size();
                maxLength = max(maxLength, strLen);
            }
        }

        return maxLength;
    }
};