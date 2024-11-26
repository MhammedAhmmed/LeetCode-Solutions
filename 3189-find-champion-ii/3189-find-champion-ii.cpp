class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<bool> teams(n, true);

        for (auto edge : edges) {
            teams[edge[1]] = false;
        }

        int res = -1;

        for (int i = 0; i < n; i++) {
            if (teams[i]) {
                if (res != -1)
                    return -1;

                res = i;
            }
        }

        return res;
    }
};