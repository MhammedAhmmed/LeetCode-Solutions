class Solution {

    void colorComp(int node, int color, vector<vector<int>> adj,
                   vector<int>& colors) {

        colors[node] = color;

        for (int v : adj[node]) {
            if (colors[v] == -1) {
                colorComp(v, color, adj, colors);
            }
        }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for (vector<int> edge : edges) {
            int from = edge[0];
            int to = edge[1];

            adj[from].push_back(to);
            adj[to].push_back(from);
        }

        vector<int> colors(n, -1);
        unordered_map<int, int> freq;
        unordered_set<int> comps;
        int color = 0;

        for (int i = 0; i < n; i++) {
            if (colors[i] == -1) {
                comps.insert(color);
                colorComp(i, color++, adj, colors);
            }

            freq[colors[i]]++;
        }

        for (int i = 0; i < n; i++) {
            if (adj[i].size() != freq[colors[i]] - 1) {
                comps.erase(colors[i]);
            }
        }

        return comps.size();
    }
};