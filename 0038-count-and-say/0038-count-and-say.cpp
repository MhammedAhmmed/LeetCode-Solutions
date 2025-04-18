class Solution {
    string stringProcessing(string s) {
        int n = s.size();
        string res = "";

        for (int i = 0; i < n; i++) {
            int len = 0;
            char num = s[i];

            while (i < n && s[i] == num) {
                len++;
                i++;
            }

            i--;

            res += to_string(len);
            res.push_back(num);
        }

        return res;
    }

public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }

        string count = countAndSay(n - 1);

        return stringProcessing(count);
    }
};