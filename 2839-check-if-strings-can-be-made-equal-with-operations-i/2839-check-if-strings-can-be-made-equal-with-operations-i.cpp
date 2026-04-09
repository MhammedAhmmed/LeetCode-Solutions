class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1 == s2){
            return true;
        }
        string temp = s1;
        char ch = temp[2];
        temp[2] = temp[0];
        temp[0] = ch;
        if(temp == s2){
            return true;
        }
        temp = s1;
        ch = temp[3];
        temp[3] = temp[1];
        temp[1] = ch;
        if(temp == s2){
            return true;
        }
        ch = temp[2];
        temp[2] = temp[0];
        temp[0] = ch;
        if(temp == s2){
            return true;
        }
        return false;
    }
};