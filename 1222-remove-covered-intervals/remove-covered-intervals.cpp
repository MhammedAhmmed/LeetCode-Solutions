class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b){
            if(a[0] != b[0]){
                return a[0] < b[0];
            }
            return a[1] > b[1];
        });

        int n = intervals.size();
        set<int>rs;
        int sum = 0;
        for(int i = 0; i < n; i++){
            int r = intervals[i][1];
            if(rs.lower_bound(r) == rs.end()){
                sum++;
            }
            rs.insert(intervals[i][1]);
        }
        return sum;
    }
};