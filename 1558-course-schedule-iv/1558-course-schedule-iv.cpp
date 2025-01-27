class Solution {
public:
    unordered_set<int> fillPreRequisutes(int v, vector<vector<int>>& adj,
                                         vector<unordered_set<int>>& pre,
                                         vector<bool>& vis) {
        if (vis[v]) {
            return pre[v];
        }
        vis[v] = true;

        unordered_set<int> nodePre;

        for (int node : adj[v]) {
            unordered_set<int> temp = fillPreRequisutes(node, adj, pre, vis);

            for (auto x : temp) {
                nodePre.insert(x);
            }
        }

        nodePre.insert(v);
        for (auto x : nodePre) {
            pre[v].insert(x);
        }

        return nodePre;
    }
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {

        vector<vector<int>> adj(numCourses);
        vector<unordered_set<int>> pre(numCourses);

        for (vector<int> prerequisite : prerequisites) {
            adj[prerequisite[0]].push_back(prerequisite[1]);
        }

        vector<bool> vis(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            fillPreRequisutes(i, adj, pre, vis);
        }

        int n = queries.size();

        vector<bool> res(n);

        for (int i = 0; i < n; i++) {
            int u = queries[i][0];
            int v = queries[i][1];

            if (pre[u].find(v) == pre[u].end()) {
                res[i] = false;
            } else {
                res[i] = true;
            }
        }

        return res;
    }
};