class Solution {
    double
    calcDivision(string src, string dest, unordered_map<string, bool>& vis,
                 unordered_map<string, vector<pair<string, double>>>& adj) {
        if (src == dest) {
            return 1;
        }

        vis[src] = true;

        for (pair<string, double> p : adj[src]) {
            if (!vis[p.first]) {
                double val = calcDivision(p.first, dest, vis, adj);

                if (val >= 0) {
                    return val * p.second;
                }
            }
        }

        return -1;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;

        int n = equations.size();

        for (int i = 0; i < n; i++) {
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }

        int len = queries.size();
        vector<double> res(len);

        for (int i = 0; i < len; i++) {
            if (adj.find(queries[i][0]) == adj.end() ||
                adj.find(queries[i][1]) == adj.end()) {
                res[i] = -1;
            } else {
                unordered_map<string, bool> vis;
                res[i] = calcDivision(queries[i][0], queries[i][1], vis, adj);
            }
        }

        for (int i = 0; i < len; i++) {
            cout << res[i] << " ";
        }
        return res;
    }
};