class Solution {
    string withoutSpace(string s, vector<int>& l, vector<int>& r) {
        string res = "";
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '_') {
                continue;
            }

            res.push_back(s[i]);
            if (s[i] == 'L') {
                l.push_back(i);
            } else {
                r.push_back(i);
            }
        }

        return res;
    }

public:
    bool canChange(string start, string target) {
        vector<int> sl, sr;
        string s = withoutSpace(start, sl, sr);

        vector<int> tl, tr;
        string t = withoutSpace(target, tl, tr);

        if (s != t) {
            return false;
        }

        int leftN = sl.size();
        for (int i = 0; i < leftN; i++) {
            if (sl[i] < tl[i]) {
                return false;
            }
        }

        int rightN = sr.size();
        for (int i = 0; i < rightN; i++) {
            if (sr[i] > tr[i]) {
                return false;
            }
        }

        return true;
    }
};