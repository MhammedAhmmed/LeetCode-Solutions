class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> freq;

        for (char ch : s1) {
            freq[ch]++;
        }

        int n = s2.size(), len = 0;

        int p1 = 0, p2 = 0;
        unordered_map<char, int> temp;

        while (p2 < n) {
            if (freq.find(s2[p2]) == freq.end()) {
                for (auto entry : temp) {
                    temp[entry.first] = 0;
                }
                p1 = p2 = p2 + 1;
                len = 0;
                continue;
            }

            temp[s2[p2]]++;

            if (temp[s2[p2]] > freq[s2[p2]]) {
                while (temp[s2[p2]] > freq[s2[p2]]) {
                    temp[s2[p1]]--;
                    p1++;
                    len--;
                }
            }

            len++;
            if (len == s1.size()) {
                return true;
            }

            p2++;
        }

        return false;
    }
};