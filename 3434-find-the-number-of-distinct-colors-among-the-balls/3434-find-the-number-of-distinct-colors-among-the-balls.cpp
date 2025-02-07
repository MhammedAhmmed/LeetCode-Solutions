class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>ballColor, freq;

        int n = queries.size();
        vector<int>res(n);

        for(int i = 0; i < n; i++){
            int ball = queries[i][0];
            int color = queries[i][1];

            if(ballColor[ball] != 0){
                freq[ballColor[ball]]--;

                if(freq[ballColor[ball]] == 0){
                    freq.erase(ballColor[ball]);
                }
            }
            ballColor[ball] = color;
            freq[color]++;

            res[i] = freq.size();
        }
        return res;
    }
};