class Solution {
public:
    bool checkString(string s) {
        int i = 0, n = s.size();

        while(i < n && s[i] == 'a'){
            i++;
        }

        while(i < n && s[i] == 'b'){
            i++;
        }
        return i == n;
    }
};