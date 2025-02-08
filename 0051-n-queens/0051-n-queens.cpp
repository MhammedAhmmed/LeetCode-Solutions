class Solution {
    bool validCombination(vector<int>&pos, int n){
        
        int row, col;
        for(int i = 0; i < n - 1; i++){
            row = pos[i];
            col = i;

            while(row + 1 < n && col + 1 < n){
                if(pos[col + 1] == row + 1){
                    return false;
                }
                row++;
                col++;
            }

            row = pos[i];
            col = i;

            while(row - 1 >= 0 && col + 1 < n){
                if(pos[col + 1] == row - 1){
                    return false;
                }
                row--;
                col++;
            }
        }

        return true;
    }
    vector<string> generateSol(vector<int>&pos, int n){
        
        string rowPos = "";
        for(int i = 0; i < n; i++){
            rowPos.push_back('.');
        }

        vector<string>sol(n);
        for(int i = 0; i < n; i++){
            rowPos[i] = 'Q';

            sol[pos[i]] = rowPos; 

            rowPos[i] = '.';
        }

        return sol;
    }

    vector<vector<string>>res;
    void solve(vector<bool>&rowTake, vector<int>&pos, int index, int n){
        if(index == n){
            if(validCombination(pos, n)){
                res.push_back(generateSol(pos, n));

            }

            return;
        }

        for(int i = 0; i < n; i++){
            if(!rowTake[i]){
                rowTake[i] = 1;
                pos[index] = i;

                solve(rowTake, pos, index + 1, n);

                rowTake[i] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<bool>rowTake(n, false);
        vector<int>pos(n);

        solve(rowTake, pos, 0, n);
        
        return res;
    }
};