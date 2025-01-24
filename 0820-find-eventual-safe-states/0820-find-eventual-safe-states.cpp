class Solution {
    bool dfs(int v, vector<vector<int>>& graph, vector<bool>& vis,
             vector<bool>& isSafe) {
        vis[v] = true;

        bool safe = true;

        for (int adj : graph[v]) {
            if (vis[adj]) {
                safe = safe && isSafe[adj];
            } else {
                safe = safe && dfs(adj, graph, vis, isSafe);
            }
        }

        return isSafe[v] = safe;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<bool> vis(n, false), isSafe(n, false);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, graph, vis, isSafe);
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (isSafe[i]) {
                res.push_back(i);
            }
        }

        return res;
    }
};