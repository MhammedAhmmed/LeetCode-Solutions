class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int>pFreq(26, 0);
        for(char ch: p){
            pFreq[ch - 'a']++;
        }

        int p1 = 0, p2 = 0, n = s.size();
        vector<int>curFreq(26, 0);
        int len = p.size();

        vector<int>res;
        while(p2 < n){
            curFreq[s[p2] - 'a']++;

            if(pFreq[s[p2] - 'a'] >= curFreq[s[p2] - 'a']){
                if(p2 - p1 + 1 == len){
                    res.push_back(p1);
                    curFreq[s[p1] - 'a']--;
                    p1++;
                }
            }
            else{
                while(curFreq[s[p2] - 'a'] > pFreq[s[p2] - 'a']){
                    curFreq[s[p1] - 'a']--;
                    p1++;
                }
            }

            p2++;
        }

        return res;
    }
};