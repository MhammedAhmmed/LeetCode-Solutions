class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        
        int n = colors.size();

        int p1 = 0, p2 = 1, len = 1;
        int res = 0;
        while(p1 < n){
            if(colors[p2] == colors[(p2 - 1 + n) % n]){
                if(p2 < p1){
                    break;
                }
                
                p1 = p2; 
                len = 1;
            }else{
                len++;

                if(len == k){
                    res++;
                    p1++;
                    len--;
                }
            }

            p2 = (p2 + 1) % n;
        }

        return res;
    }
};