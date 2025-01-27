class Solution {
public:
    bool orderExist(int v, vector<vector<int>>& adj, vector<bool>& vis,
                    vector<bool>& inStack, stack<int>& order) {

        vis[v] = inStack[v] = true;

        for (int node : adj[v]) {
            if (inStack[node]) {
                return false;
            }

            if (!vis[node]) {
                bool sol = orderExist(node, adj, vis, inStack, order);

                if (!sol) {
                    return false;
                }
            }
        }
        order.push(v);
        inStack[v] = false;

        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (vector<int> pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        vector<bool> vis(numCourses, false), inStack(numCourses, false);

        stack<int> order;
        vector<int> res;
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (!orderExist(i, adj, vis, inStack, order)) {
                    return res;
                }
            }
        }

        while (!order.empty()) {
            res.push_back(order.top());
            order.pop();
        }

        return res;
    }
};