class Solution {
public:
    int secondHighest(string s) {
        vector<bool>digit(10, false);

        for(char ch : s){
            if(ch >= '0' && ch <= '9'){
                digit[ch - '0'] = 1;
            }
        }

        bool first = false;

        for(int i = 9; i >= 0; i--){
            if(digit[i]){
                if(first){
                    return i;
                }
                first = 1;
            }
        }

        return -1;
    }
};