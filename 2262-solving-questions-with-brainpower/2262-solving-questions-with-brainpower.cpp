class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();

        vector<long long>points(n);

        points[n - 1] = questions[n - 1][0];

        for (int i = n - 2; i >= 0; i--) {
            int next = questions[i][1] + i + 1;

            if (next >= n) {
                points[i] = max(points[i + 1], (long long)questions[i][0]);
            }
            else {
                points[i] = max(points[i + 1], questions[i][0] + points[next]);
            }
        }
        return points[0];
    }
};