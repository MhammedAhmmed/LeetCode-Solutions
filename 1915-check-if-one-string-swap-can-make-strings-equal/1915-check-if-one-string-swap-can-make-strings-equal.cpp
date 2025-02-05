class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();

        if(n1 != n2){
            return false;
        }

        unordered_map<char,int>freq;

        for(char ch: s1){
            freq[ch]++;
        }
        
        for(char ch: s2){
            freq[ch]--;
        }

        for(auto entry: freq){
            if(entry.second != 0){
                return false;
            }
        }

        int diff = 0;
        for(int i = 0; i < n1; i++){
            if(s1[i] != s2[i]){
                diff++;
            }
        }
        
        return diff <= 2;
    }
};