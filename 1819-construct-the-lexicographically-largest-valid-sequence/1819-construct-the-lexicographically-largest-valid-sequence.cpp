class Solution {
    bool sequence(vector<int>&seq, vector<bool>&take, int n, int index){
        if(index >= 2 * n - 1){
            for(int i = 1; i <= n; i++){
                if(!take[i]){
                    return false;
                }
            }
            return true;
    }

        if(seq[index] != -1){
            return sequence(seq, take, n, index + 1);
        }

        for(int i = n; i >= 2; i--){
            if(index + i >= (2 * n - 1) || take[i] || seq[index + i] != -1){
                continue;
            }

            take[i] = true;
            seq[index] = seq[index + i] = i;

            if(sequence(seq, take, n, index + 1)){
                return true;
            }

            take[i] = false;
            seq[index] = seq[index + i] = -1;
        }

        if(!take[1]){   
            take[1] = true;
            seq[index] = 1;

            if(sequence(seq, take, n, index + 1)){
                return true;
            }

            take[1] = false;
            seq[index] = -1;
        }
        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        vector<bool>take(n + 1, false);
        vector<int>seq(2 * n - 1, -1);

        sequence(seq, take, n, 0);
        
        return seq;
    }
};