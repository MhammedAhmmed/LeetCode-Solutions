class Solution {
    int uniqueSplit(string s, int index, unordered_set<string>& substrings) {
        if (index >= s.size())
            return 0;

        int n = s.size();
        string temp = "";
        int res = -1;

        for (int i = index; i < n; i++) {
            temp.push_back(s[i]);

            if (substrings.find(temp) == substrings.end()) {
                substrings.insert(temp);

                int remainSubs = uniqueSplit(s, i + 1, substrings);

                if (remainSubs != -1) {
                    res = max(res, 1 + remainSubs);
                }

                substrings.erase(temp);
            }
        }

        return res;
    }

public:
    int maxUniqueSplit(string s) {
        unordered_set<string> us;

        return uniqueSplit(s, 0, us);
    }
};