class Solution {
    bool isOperator(string token) {

        return token.size() == 1 && (token[0] == '+' || token[0] == '-' ||
                                     token[0] == '*' || token[0] == '/');
    }
    int doOperation(int num1, int num2, string op) {
        if (op == "+") {
            return num1 + num2;
        } else if (op == "-") {
            return num1 - num2;
        } else if (op == "*") {
            return num1 * num2;
        } 
        return num1 / num2;
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string token : tokens) {

            if (isOperator(token)) {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();

                st.push(doOperation(num1, num2, token));
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};