class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size(), ns = spaces.size();

        string res = "";
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (j < ns && i == spaces[j]) {
                res.push_back(' ');
                i--;
                j++;
            } else {
                res.push_back(s[i]);
            }
        }

        return res;
    }
};