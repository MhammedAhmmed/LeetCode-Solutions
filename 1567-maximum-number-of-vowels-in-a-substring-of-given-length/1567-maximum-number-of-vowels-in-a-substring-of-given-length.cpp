class Solution {
public:
    int maxVowels(string s, int k) {
        int res = 0, p1 = 0, p2 = 0;
        int n = s.size();

        map<char, int> freq;
        while (p2 < n) {
            freq[s[p2]]++;

            if (p2 - p1 + 1 == k) {
                int vowel =
                    freq['a'] + freq['i'] + freq['e'] + freq['o'] + freq['u'];
                res = max(res, vowel);

                freq[s[p1]]--;
                p1++;
            }

            p2++;
        }
        return res;
    }
};