class Solution {
    char calculateExpression(vector<char>& subExp, char op) {
        if (op == '!') {
            if (subExp[0] == 'f')
                return 't';
            else
                return 'f';
        }

        if (op == '&') {
            for (char ch : subExp) {
                if (ch == 'f')
                    return 'f';
            }

            return 't';
        }

        if (op == '|') {
            for (char ch : subExp) {
                if (ch == 't')
                    return 't';
            }
            return 'f';
        }

        return 'f';
    }

public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        int n = expression.size();

        for (int i = 0; i < n; i++) {
            if (expression[i] == ',')
                continue;
            if (expression[i] == ')') {
                vector<char> subExp;

                while (st.top() != '(') {
                    subExp.push_back(st.top());
                    st.pop();
                }

                st.pop();

                char op = st.top();
                st.pop();

                st.push(calculateExpression(subExp, op));

            } else {
                st.push(expression[i]);
            }
        }

        return st.top() == 't';
    }
};