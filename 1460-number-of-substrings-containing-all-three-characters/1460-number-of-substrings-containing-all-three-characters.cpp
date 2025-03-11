class Solution {
public:
    int numberOfSubstrings(string s) {

        vector<int> freq(3, 0);
        int res = 0;

        int p1 = 0, p2 = 0, n = s.size();

        while (p2 < n) {
            freq[s[p2] - 'a']++;

            while (freq[0] && freq[1] && freq[2]) {
                res += (n - p2);

                freq[s[p1] - 'a']--;
                p1++;
            }

            p2++;
        }

        return res;
    }
};