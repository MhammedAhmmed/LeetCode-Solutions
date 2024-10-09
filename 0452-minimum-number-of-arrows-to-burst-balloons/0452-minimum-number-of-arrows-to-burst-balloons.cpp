class Solution {
bool intersect(vector<int>& v1, vector<int>& v2) {
	return v1[0] <= v2[1] && v2[0] <= v1[1];
}
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());

        int n = points.size();
        int numOfShots = 0;

        for (int i = 0; i < n; i++) {
            numOfShots++;
            vector<int> cur = points[i];

            while (i < n && intersect(cur, points[i])) {
                cur[0] = max(cur[0], points[i][0]);
                cur[1] = min(cur[1], points[i][1]);
                i++;
            }
            i--;
        }

        return numOfShots;
    }
};