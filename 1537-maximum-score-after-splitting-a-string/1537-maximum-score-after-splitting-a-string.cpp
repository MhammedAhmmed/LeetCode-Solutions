class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int ones = 0, zeros = 0;

        for(int i = 1; i < n; i++){
            if(s[i] == '1'){
                ones++;
            }
        }
        if(s[0] == '0'){
            zeros++;
        }


        int res = zeros + ones;
        for(int i = 1;i < n-1; i++){
            if(s[i] == '1'){
                ones--;
            }else{
                zeros++;
            }

            res = max(res, zeros + ones);
        }

        return res;
    }
};