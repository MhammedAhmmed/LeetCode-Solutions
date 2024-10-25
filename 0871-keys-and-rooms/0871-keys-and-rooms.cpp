class Solution {
    void dfs(vector<vector<int>>& adj, int node, vector<bool>& vis) {
        vis[node] = true;

        for (int v : adj[node]) {
            if (!vis[v]) {
                dfs(adj, v, vis);
            }
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int key : rooms[i]) {
                adj[i].push_back(key);
            }
        }

        vector<bool> vis(n, false);
        dfs(adj, 0, vis);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                return false;
            }
        }
        return true;
    }
};