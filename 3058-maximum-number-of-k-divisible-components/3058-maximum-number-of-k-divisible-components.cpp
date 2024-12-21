class Solution {
    int res = 1;

    long long dfs(int V, vector<vector<int>>& adj, vector<int>& values,
                  vector<bool>& vis, int k) {
        vis[V] = 1;

        long long sum = values[V];

        for (int v : adj[V]) {
            if (!vis[v]) {
                long long componentSum = dfs(v, adj, values, vis, k);

                if (componentSum % k == 0) {
                    res++;
                }
                sum += componentSum;
            }
        }

        return sum;
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        vector<vector<int>> adj(n);

        for (vector<int> edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> vis(n, false);

        dfs(0, adj, values, vis, k);
        return res;
    }
};