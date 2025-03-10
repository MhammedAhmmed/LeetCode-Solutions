class Solution {
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'i' || ch == 'e' || ch == 'o' || ch == 'u';
    }

public:
    long long atLeastK(string word, int k) {

        int n = word.size();

        vector<int> freq(26, 0);
        int vow = 0, con = 0;

        int p1 = 0, p2 = 0;
        long long res = 0;

        while (p2 < n) {
            if (isVowel(word[p2])) {
                if (freq[word[p2] - 'a'] == 0) {
                    vow++;
                }
            } else {
                con++;
            }

            freq[word[p2] - 'a']++;

            while (vow == 5 && con >= k) {
                res += (n - p2);

                freq[word[p1] - 'a']--;

                if (isVowel(word[p1])) {
                    if (freq[word[p1] - 'a'] == 0) {
                        vow--;
                    }
                } else {
                    con--;
                }
                p1++;
            }

            p2++;
        }

        return res;
    }
    long long countOfSubstrings(string word, int k) {

        return atLeastK(word, k) - atLeastK(word, k + 1);
    }
};