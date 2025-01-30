class Solution {
public:
    bool bibartite(int v, vector<vector<int>>& adj, vector<int>& color,
                   vector<int>& component, int num) {
        component[v] = num;

        for (int node : adj[v]) {
            if (color[node] == color[v]) {
                return false;
            }

            if (color[node] == -1) {
                color[node] = 1 - color[v];
                if (!bibartite(node, adj, color, component, num)) {
                    return false;
                }
            }
        }

        return true;
    }
    int bfs(int v, int n, vector<vector<int>>& adj) {

        queue<int> q;
        q.push(v);
        vector<int> vis(n + 1, false);
        vis[v] = 1;

        int groups = 0;
        while (!q.empty()) {
            int len = q.size();

            while (len--) {
                int top = q.front();
                q.pop();

                for (int node : adj[top]) {
                    if (!vis[node]) {
                        vis[node] = 1;
                        q.push(node);
                    }
                }
            }

            groups++;
        }

        return groups;
    }
    int allChoices(int num, int n, vector<vector<int>>& adj,
                   vector<int>& compnent) {

        int maxGroups = 0;
        for (int i = 1; i <= n; i++) {
            if (compnent[i] == num) {
                maxGroups = max(maxGroups, bfs(i, n, adj));
            }
        }

        return maxGroups;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);

        for (vector<int> edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> color(n + 1, -1), component(n + 1, 0);

        int groups = 0;
        int num = 1;
        for (int i = 1; i <= n; i++) {

            if (color[i] == -1) {
                color[i] = 0;
                if (!bibartite(i, adj, color, component, num)) {
                    return -1;
                }
                groups += allChoices(num, n, adj, component);
            }

            num++;
        }

        return groups;
    }
};