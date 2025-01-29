class Solution {
public:
    int findOp(int v, vector<int>& parents) {
        int parent = v;

        while (parent != parents[parent]) {
            parent = parents[parent];
        }

        while (v != parent) {
            int temp = parents[v];
            parents[v] = parent;
            v = temp;
        }

        return parent;
    }

    bool connected(int v, int u, vector<int>& parents) {
        return findOp(v, parents) == findOp(u, parents);
    }
    void unionOp(int v, int u, vector<int>& parents, vector<int>& weight) {
        int vParent = findOp(v, parents);
        int uParent = findOp(u, parents);

        if (weight[vParent] > weight[uParent]) {
            weight[vParent] += weight[uParent];
            parents[uParent] = vParent;
        } else {
            weight[uParent] += weight[vParent];
            parents[vParent] = uParent;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> parents(n + 1), weight(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            parents[i] = i;
        }

        for (vector<int> edge : edges) {
            if (connected(edge[0], edge[1], parents)) {
                cout << edge[0] << " " << edge[1];
                return edge;
            }

            unionOp(edge[0], edge[1], parents, weight);
        }

        vector<int> res;
        return res;
    }
};