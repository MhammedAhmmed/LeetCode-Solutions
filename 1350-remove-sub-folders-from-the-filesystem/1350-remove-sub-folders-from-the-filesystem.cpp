class Solution {
    vector<string> splitString(string s) {
        int n = s.size();

        vector<string> res;

        for (int i = 0; i < n; i++) {
            if (s[i] == '/')
                continue;

            string temp = "/";
            while (i < n && s[i] != '/') {
                temp.push_back(s[i]);
                i++;
            }

            res.push_back(temp);
        }

        return res;
    }

public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end(),
             [](const std::string& a, const std::string& b) {
                 return a.length() < b.length();
             });

        unordered_set<string> us;
        us.insert(folder[0]);

        int n = folder.size();
        vector<string> res;
        res.push_back(folder[0]);

        for (int i = 1; i < n; i++) {
            vector<string> stringSplit = splitString(folder[i]);
            string temp = "";
            bool found = false;
            for (string str : stringSplit) {
                temp += str;
                if (us.find(temp) != us.end()) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                us.insert(temp);
                res.push_back(temp);
            }
        }

        return res;
    }
};