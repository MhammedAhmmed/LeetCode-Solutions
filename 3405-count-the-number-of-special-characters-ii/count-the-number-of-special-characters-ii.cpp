class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, vector<char>>mp;

        for(char ch: word){
            mp[tolower(ch)].push_back(ch);
        }

        int res = 0;
        for(auto e: mp){
            vector<char>chL = e.second;
            bool lower = false, upper = false, match = true;
            for(char ch: chL){
                if(ch >= 'a'){
                    if(upper){
                        match = false;
                        break;
                    }
                    lower = true;
                }else{
                    upper = true;
                }
            }
            if(match && lower && upper){
                res++;
            }
        }
        return res;
        
    }
};