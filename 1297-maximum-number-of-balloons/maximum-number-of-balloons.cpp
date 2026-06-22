class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>freq(26, 0);

        for(char ch: text){
            freq[ch - 'a']++;
        }

        int res = 0;
        while(true){
            if(freq['a' - 'a'] && freq['b' - 'a'] && freq['l' - 'a'] > 1
            && freq['o' - 'a'] > 1 && freq['n' - 'a']){
                freq['a' - 'a']--;
                freq['b' - 'a']--;
                freq['l' - 'a'] -= 2;
                freq['o' - 'a'] -= 2;
                freq['n' - 'a']--;
                res++;
            }else{
                break;
            }
        }
        return res;   
    }
};