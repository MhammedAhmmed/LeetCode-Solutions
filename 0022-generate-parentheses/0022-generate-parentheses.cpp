class Solution {
    bool isOn(int num, int index) { return (num >> index) & 1; }
    string generateParanthe(int num, int k) {
        string res = "";
        for (int i = 0; i < k; i++) {
            if (isOn(num, i)) {
                res.push_back(')');
            } else {
                res.push_back('(');
            }
        }

        return res;
    }

    bool valid(string s) {
        stack<char> st;

        for (char ch : s) {
            if (ch == '(') {
                st.push('(');
            } else {
                if (st.empty()) {
                    return false;
                }

                st.pop();
            }
        }

        return st.empty();
    }

public:
    vector<string> generateParenthesis(int n) {
        unordered_set<string> allGenerations;

        int power = pow(2, 2 * n);
        int k = n * 2;
        for (int i = 0; i < power; i++) {
            string para = generateParanthe(i, k);

            if (valid(para)) {
                allGenerations.insert(para);
            }
        }

        vector<string> res;

        for (auto entry : allGenerations) {
            res.push_back(entry);
        }

        return res;
    }
};