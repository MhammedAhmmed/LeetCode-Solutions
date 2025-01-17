class Solution {
public:
    string decodeString(string s) {
        stack<char> st;

        int n = s.size();
        for (int i = n - 1; i >= 0; i--) {
            st.push(s[i]);
        }

        string res = "", numS = "";
        while (!st.empty()) {
            char ele = st.top();
            st.pop();

            if (ele >= 'a' && ele <= 'z') {
                res.push_back(ele);
            } else if (ele >= '0' && ele <= '9') {
                numS.push_back(ele);
            } else {
                int sum = -1;
                string word = "";
                while (sum != 0) {
                    char ch = st.top();
                    st.pop();

                    if (ch == '[') {
                        sum--;
                    } else if (ch == ']') {
                        sum++;
                    }

                    word.push_back(ch);
                }
                word.pop_back();

                int num = stoi(numS);
                int wordLen = word.size();
                while (num--) {
                    for (int i = wordLen - 1; i >= 0; i--) {
                        st.push(word[i]);
                    }
                }
                numS = "";
            }
        }

        return res;
    }
};