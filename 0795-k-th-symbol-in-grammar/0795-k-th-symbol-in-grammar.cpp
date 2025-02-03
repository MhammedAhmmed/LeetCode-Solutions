class Solution {
    int getKthGrammar(int n, int k, bool same) {
        if(n == 1){
            if(same){
                return 0;
            }
            return 1;
        }
        
        int space = pow(2, n - 1);

        if(k <= space / 2){
            return getKthGrammar(n - 1, k, same);
        }
        return getKthGrammar(n - 1, k - space / 2, !same);
    }
public:
    int kthGrammar(int n, int k) {
        return getKthGrammar(n, k, true);
    }
};