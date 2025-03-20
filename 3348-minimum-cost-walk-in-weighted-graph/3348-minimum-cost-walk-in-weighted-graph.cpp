class Solution {
public:
    void colorAndWeight(int V, int& weight, vector<vector<pair<int, int>>>& adj,
                        int color, vector<int>& colors) {

        if (colors[V] != -1) {
            return;
        }

        colors[V] = color;

        for (pair<int, int> node : adj[V]) {
            weight &= node.second;

            colorAndWeight(node.first, weight, adj, color, colors);
        }
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& query) {

        vector<vector<pair<int, int>>> adj(n);

        for (vector<int> edge : edges) {
            int from = edge[0];
            int to = edge[1];
            int weight = edge[2];

            adj[from].push_back({to, weight});
            adj[to].push_back({from, weight});
        }

        vector<int> colors(n, -1);
        int color = 0;

        unordered_map<int, int> minWeight;

        for (int i = 0; i < n; i++) {
            if (colors[i] == -1) {

                if (adj[i].size() != 0) {
                    int weight = adj[i][0].second;

                    colorAndWeight(i, weight, adj, color, colors);

                    minWeight[color] = weight;
                }

                colors[i] = color;
                color++;
            }
        }

        int m = query.size();
        vector<int> res(m);

        for (int i = 0; i < m; i++) {
            int from = query[i][0];
            int to = query[i][1];

            if (colors[from] == colors[to] && (colors[from] != -1)) {
                res[i] = minWeight[colors[from]];
            } else {
                res[i] = -1;
            }
        }

        return res;
    }
};