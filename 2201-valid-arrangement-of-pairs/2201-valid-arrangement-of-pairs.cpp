class Solution {
    void dfs(unordered_map<int, vector<int>>& adj, int V, stack<int>& st,
             unordered_map<int, int>& outdegree) {

        while (outdegree[V]) {
            int next = adj[V][--outdegree[V]];

            dfs(adj, next, st, outdegree);
        }
        st.push(V);
    }

public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, int> indegree, outdegree;

        unordered_map<int, vector<int>> adj;
        for (auto pair : pairs) {
            adj[pair[0]].push_back(pair[1]);

            outdegree[pair[0]]++;
            indegree[pair[1]]++;
        }

        int initialNode = pairs[0][0];

        for (auto entry : outdegree) {
            if (outdegree[entry.first] == indegree[entry.first] + 1) {
                initialNode = entry.first;
                break;
            }
        }

        stack<int> st;
        dfs(adj, initialNode, st, outdegree);

        int n = pairs.size();
        vector<vector<int>> res(n, vector<int>(2));

        for (int i = 0; i < n; i++) {
            vector<int> pair(2);

            pair[0] = st.top();
            st.pop();
            pair[1] = st.top();

            res[i] = pair;
        }

        return res;
    }
};