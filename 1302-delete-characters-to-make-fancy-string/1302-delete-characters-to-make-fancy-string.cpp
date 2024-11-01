class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        if(n < 3){
            return s;
        }


        string res = "";

        for(int i = 0; i < n - 2; i++){
            if(s[i] == s[i+1] && s[i+1] == s[i+2]){
                continue;
            }
            res.push_back(s[i]);
        }

        res.push_back(s[n-2]);
        res.push_back(s[n-1]);

        return res;
    }
};