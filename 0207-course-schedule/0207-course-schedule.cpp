class Solution {
    bool cycleExist(int v, vector<vector<int>>& adj, vector<bool>& vis,
                    vector<bool>& inStack) {
        vis[v] = true;
        inStack[v] = true;

        for (int node : adj[v]) {
            if (inStack[node]) {
                return true;
            }

            if (!vis[node]) {
                bool cycle = cycleExist(node, adj, vis, inStack);

                if (cycle) {
                    return true;
                }
            }
        }
        inStack[v] = false;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (vector<int> pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        vector<bool> vis(numCourses, false), inStack(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (cycleExist(i, adj, vis, inStack)) {
                    return false;
                }
            }
        }

        return true;
    }
};