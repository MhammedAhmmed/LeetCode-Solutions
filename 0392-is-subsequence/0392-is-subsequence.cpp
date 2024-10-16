class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ns = s.size(), nt = t.size();

        int p1 = 0;

        for (int i = 0; i < nt; i++) {
            if (t[i] == s[p1]) {
                p1++;
                if (p1 == ns)
                    break;
            }
        }

        return p1 == ns;
    }
};