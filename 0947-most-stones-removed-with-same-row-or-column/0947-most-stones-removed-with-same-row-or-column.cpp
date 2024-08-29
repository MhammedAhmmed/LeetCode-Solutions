class Solution {
    void removeStonesLevels(vector<vector<int>>& stones, int n, vector<vector<int>>&preLevel, vector<bool>& take) {
	if (preLevel.empty())
		return;

	int len = preLevel.size();
	vector<vector<int>>nextLevel;

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < n; j++) {
			if (take[j] || (preLevel[i][0] == stones[j][0] && preLevel[i][1] == stones[j][1]))
				continue;

			if (preLevel[i][0] == stones[j][0] || preLevel[i][1] == stones[j][1]) {
				take[j] = 1;
				nextLevel.push_back({ stones[j][0], stones[j][1] });
			}
		}
	}
	removeStonesLevels(stones, n, nextLevel, take);
}
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        vector<bool>take(n, false);
        vector<vector<int>>firstLevel;

        for (int i = 0; i < n; i++) {
            if (!take[i]) {
                take[i] = 1;
                firstLevel.push_back(stones[i]);
                removeStonesLevels(stones, n, firstLevel, take);
                firstLevel.pop_back();
                take[i] = 0;
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (take[i])
                res++;
        }

        return res;
    }
};