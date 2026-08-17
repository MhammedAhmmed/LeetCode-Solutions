class Solution {
    void sequentialN(int n, vector<int>&seq){
        for(int i = 1; i <= 10 - n; i++){
            string num = "";
            for(int j = 0; j < n; j++){
                num += to_string(i + j);
            }
            seq.push_back(stoi(num));
        }
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>seq;
        for(int i = 2; i <= 10; i++){
            sequentialN(i, seq);
        }
        vector<int>res;
        for(int num : seq){
            if(num >= low && num <= high){
                res.push_back(num);
            }
        }
        return res;
    }
};