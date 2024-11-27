class Solution {
    int shortestDistance(vector<vector<int>>& adj, int from, int to) {

        queue<int> q;
        vector<int> vis(to + 1, false);
        q.push(from);
        vis[from] = true;

        int level = 0;

        while (!q.empty()) {
            queue<int> temp;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                if (node == to) {
                    return level;
                }

                for (int v : adj[node]) {
                    if (!vis[v]) {
                        vis[v] = 1;
                        temp.push(v);
                    }
                }
            }

            q = temp;
            level++;
        }

        return 0;
    }

public:
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);

        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }

        int len = queries.size();
        vector<int> res(len);

        for (int i = 0; i < len; i++) {
            adj[queries[i][0]].push_back(queries[i][1]);

            res[i] = shortestDistance(adj, 0, n - 1);
        }

        return res;
    }
};