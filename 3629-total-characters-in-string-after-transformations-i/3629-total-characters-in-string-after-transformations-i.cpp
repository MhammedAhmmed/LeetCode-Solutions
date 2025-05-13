class Solution {
public:
    int lengthAfterTransformations(string s, int t) {

        int mod = 1e9 + 7;

        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        int len = 26;
        while (t--) {
            vector<int> temp(len, 0);

            for (int i = 0; i < 26; i++) {
                if (i == len - 1) {
                    temp[0] = freq[i];
                    temp[1] = (temp[1] + freq[i]) % mod;
                } else {
                    temp[i + 1] = freq[i];
                }
            }

            freq = temp;
        }

        int res = 0;
        for (int f : freq) {
            res = (res + f) % mod;
        }

        return res;
    }
};