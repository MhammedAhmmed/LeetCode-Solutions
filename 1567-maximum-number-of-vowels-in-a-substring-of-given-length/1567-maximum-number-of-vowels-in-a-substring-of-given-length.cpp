
class Solution {
public:
    int maxVowels(string s, int k) {
        vector<int> freq(26, 0);

        for (int i = 0; i < k - 1; i++) {
            freq[s[i] - 'a']++;
        }

        int res = 0;

        int p1 = 0, p2 = k - 1, n = s.size();

        while (p2 < n) {
            freq[s[p2] - 'a']++;

            int vowels = freq['a' - 'a'] + freq['i' - 'a'] + freq['e' - 'a'] +
                         freq['o' - 'a'] + freq['u' - 'a'];

            res = max(res, vowels);

            freq[s[p1] - 'a']--;

            p2++;
            p1++;
        }

        return res;
    }
};
