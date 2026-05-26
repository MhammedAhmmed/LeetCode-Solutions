class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool>existC(26, false), existS(26, false);

        for(char ch: word){
            if(ch >= 'a'){
                existS[ch-'a'] = true;
            }else{
                existC[ch-'A'] = true;
            }
        }
        int res = 0;
        for(int i = 0; i < 26; i++){
            if(existC[i] && existS[i]){
                res++;
            }
        }
        return res;
        
    }
};