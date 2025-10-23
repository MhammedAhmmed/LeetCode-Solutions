class Solution {
public:
    bool hasSameDigits(string s) {
        
        string temp;
        while(s.size() != 2){
            int len = s.size();
            temp = "";
            for(int i = 0; i < len - 1; i++){
                temp.push_back(((s[i] - '0' + s[i + 1] - '0') % 10) + '0');
            }
            s = temp;
        }
        return s[0] == s[1];
    }
};