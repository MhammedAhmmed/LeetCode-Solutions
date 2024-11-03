class Solution {
public:
    bool rotateString(string s, string goal) {
        int ns = s.size(), ng = goal.size();

        if (ns != ng)
            return false;

        for (int i = 0; i < ns; i++) {
            string temp = s.substr(i, ns);
            if (temp == goal)
                return true;

            s.push_back(s[i]);
        }

        return false;
    }
};