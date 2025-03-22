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
        int color = 0;

        for (int i = 0; i < n; i++) {
            if (colors[i] == -1) {
                colorComp(i, color++, adj, colors);
            }

            freq[colors[i]]++;
        }

        int compComponent = 0;
        for (auto compFreq : freq) {
            int compColor = compFreq.first;
            int compSize = compFreq.second;

            bool complete = true;
            for (int i = 0; i < n; i++) {
                if (colors[i] == compColor) {
                    if (adj[i].size() != compSize - 1) {
                        complete = false;
                    }
                }
            }

            if (complete) {
                compComponent++;
            }
        }

        return compComponent;
    }
};