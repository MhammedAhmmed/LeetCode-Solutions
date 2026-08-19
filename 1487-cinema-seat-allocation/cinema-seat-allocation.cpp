class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, vector<int>>usedRows;
        for(auto seat : reservedSeats){
            usedRows[seat[0]].push_back(seat[1]);
        }

        int res = 0;
        for(auto entry : usedRows){            
            vector<bool>empty(11, true);
            for(int seat : entry.second){
                empty[seat] = false;
            }
            if(empty[2] && empty[3] && empty[4] && empty[5]){
                res++;
                empty[2] = empty[3] = empty[4] = empty[5] = false;
            }
            if(empty[4] && empty[5] && empty[6] && empty[7]){
                res++;
                empty[4] = empty[5] = empty[6] = empty[7] = false;
            }
            if(empty[6] && empty[7] && empty[8] && empty[9]){
                res++;
                empty[6] = empty[7] = empty[8] = empty[9] = false;
            }
        }

        if(n > usedRows.size()){
            res += (n - usedRows.size()) * 2;
        }
        return res;
    }
};