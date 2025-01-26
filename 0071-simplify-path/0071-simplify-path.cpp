class Solution {
public:
    string simplifyPath(string path) {

        int n = path.size();
        stack<char> st;

        for (int i = 0; i < n; i++) {
            if (path[i] == '/') {
                if (st.empty() || st.top() != '/') {
                    st.push('/');
                }
            } else {
                string word = "";

                while (i < n && path[i] != '/') {
                    word.push_back(path[i++]);
                }
                i--;

                if (word == ".") {
                    continue;
                } else if (word == "..") {
                    if (st.size() != 1) {
                        st.pop();
                        while (st.top() != '/') {
                            st.pop();
                        }
                    }
                } else {
                    for (char ch : word) {
                        st.push(ch);
                    }
                }
            }
        }

        string res = "";
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        if (res.size() > 1 && res[res.size() - 1] == '/') {
            res.pop_back();
        }

        return res;
    }
};