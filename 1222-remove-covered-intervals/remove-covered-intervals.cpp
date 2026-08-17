class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<bool>remain(n, true);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j){
                    continue;
                }

                if(intervals[j][0] <= intervals[i][0] && 
                intervals[j][1] >= intervals[i][1]){
                    remain[i] = false;
                }
            }
        }

        int res = 0;
        for(int i = 0 ;i  < n; i++){
            res += remain[i];
        }
        return res;
    }
};