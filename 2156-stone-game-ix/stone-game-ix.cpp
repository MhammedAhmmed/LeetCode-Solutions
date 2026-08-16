class Solution {
    bool game(int sum, vector<int>& stones, vector<int>&freq){
        int n = stones.size() - 1;
        bool alice = false;
        for(int i = 0; i < n; i++){
            if (sum % 3 == 1){
                if(freq[0] == 0 && freq[1] == 0){
                    if(alice){
                        return false;
                    }else{
                        return true;
                    }
                }else{
                    if(freq[0]){
                        freq[0]--;
                        sum = 1;
                    }else{
                        freq[1]--;
                        sum = 2;
                    }
                }
            }else{ // sum % 3 == 2
                if(freq[0] == 0 && freq[2] == 0){
                    if(alice){
                        return false;
                    }else{
                        return true;
                    }
                }else{
                    if(freq[0]){
                        freq[0]--;
                        sum = 2;
                    }else{
                        freq[2]--;
                        sum = 1;
                    }
                }
            }
            alice = !alice;
        }
        return false;
    }
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int>freq(3, 0);
        for(int stone : stones){
            freq[stone % 3]++;
        }
        
        if(freq[0] == stones.size()){
            return false;
        }

        if(freq[1]){
            freq[1]--;
            if(game(1, stones, freq)){
                return true;
            }
        }
        freq.assign(3, 0);
        for(int stone : stones){
            freq[stone % 3]++;
        }
        if(freq[2]){
            freq[2]--;
            if(game(2, stones, freq)){
                return true;
            }
        }
        
        return false;
    }
};