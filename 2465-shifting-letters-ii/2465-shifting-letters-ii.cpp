class Solution {
    char shift(char ch, int sh) {
        if (sh >= 0) {
            if (ch + sh > 'z') {
                sh -= ('z' - ch + 1);

                return 'a' + sh;
            } else {
                return ch + sh;
            }
        } else {
            if (ch + sh < 'a') {
                sh += (ch - 'a' + 1);

                return 'z' + sh;
            } else {
                return ch + sh;
            }
        }
    }

public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> pref(n + 1, 0);

        int len = shifts.size();

        for (auto shift : shifts) {
            int st = shift[0];
            int ed = shift[1];
            int direction = shift[2];

            if (direction == 1) {
                pref[st]++;
                pref[ed + 1]--;
            } else {
                pref[st]--;
                pref[ed + 1]++;
            }
        }

        for (int i = 1; i <= n; i++) {
            pref[i] += pref[i - 1];
        }
        for (int i = 0; i < n; i++) {
            pref[i] %= 26;
        }

        for (int i = 0; i < n; i++) {
            s[i] = shift(s[i], pref[i]);
        }

        return s;
    }
};