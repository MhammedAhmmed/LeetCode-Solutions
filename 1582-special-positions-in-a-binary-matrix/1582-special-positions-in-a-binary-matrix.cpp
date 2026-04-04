class Solution {
    bool special(vector<vector<int>>& mat, int i, int j){
        for(int k = 0; k < mat.size(); k++){
            if(k == i){
                continue;
            }
            if(mat[k][j]){
                return false;
            }
        }

        for(int k = 0; k < mat[0].size(); k++){
            if(k == j){
                continue;
            }
            if(mat[i][k]){
                return false;
            }
        }
        return true;
    }
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j  = 0; j < n; j++){
                if(mat[i][j]){
                    if(special(mat, i, j)){
                        res++;
                    }
                }
            }
        }
        return res;
    }
};