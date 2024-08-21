class Solution {
int maxElement(int i, int j, vector<vector<int>>& grid) {
	int maxE = -1;
	for (int k = i; k < i + 3; k++) {
		for (int u = j; u < j + 3; u++) {
			if (grid[k][u] > maxE)
				maxE = grid[k][u];
		}
	}
	return maxE;
}
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>res(n - 2, vector<int>(n - 2));

        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                res[i][j] = maxElement(i, j, grid);
            }
        }
        return res;
    }
};