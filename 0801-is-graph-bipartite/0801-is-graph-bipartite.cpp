class Solution {
public:
    bool dfs(int v, vector<vector<int>>& graph, vector<int>& color) {

        for (int node : graph[v]) {
            if (color[node] == color[v]) {
                return false;
            }

            if (color[node] == -1) {
                color[node] = 1 - color[v];

                if (!dfs(node, graph, color)) {
                    return false;
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                color[i] = 0;
                if (!dfs(i, graph, color)) {
                    return false;
                }
            }
        }

        return true;
    }
};