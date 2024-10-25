class Solution {
    bool match(char ch1, char ch2){
        return (ch1 == '(' && ch2 == ')') || (ch1 == '{' && ch2 == '}') || (ch1 == '[' && ch2 == ']');
    }
public:
    bool isValid(string s) {
        stack<char>st;

        for(char ch : s){
            if(ch == ')' || ch == ']' || ch == '}'){
                if(st.empty())
                    return false;
                char pran = st.top();
                st.pop();

                if(!match(pran, ch)){
                    return false;
                }
            }else{
                st.push(ch);
            }
        }

        return st.empty();
    }
};