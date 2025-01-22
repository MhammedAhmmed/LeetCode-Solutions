class Solution {
    void dfs(int v, vector<bool>& vis, vector<vector<int>>& adj) {

        vis[v] = true;

        for (int node : adj[v]) {
            if (!vis[node]) {
                dfs(node, vis, adj);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;

                if (isConnected[i][j]) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<bool> vis(n, false);
        int province = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                province++;

                dfs(i, vis, adj);
            }
        }

        return province;
    }
};