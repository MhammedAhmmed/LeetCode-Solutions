class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int res = 2;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                vector<int>freq(26, 0);
                for(int k = i; k <= j; k++){
                    freq[s[k] - 'a']++;
                    if(freq[s[k] - 'a'] > 2){
                        break;
                    }
                    res = max(res, k - i + 1);
                }
            }
        }
        return res;
        
    }
};