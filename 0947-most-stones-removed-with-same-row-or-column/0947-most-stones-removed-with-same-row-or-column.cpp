class Solution {
int findOp(int v, vector<int>& parent) {
	if (v == parent[v])
		return v;

	int result = findOp(parent[v], parent);

	return parent[v] = result;
}
void Union(int v, int u, vector<int>& parent, vector<int>& size) {
	int vParent = findOp(v, parent);
	int uParent = findOp(u, parent);

	if (vParent == uParent)
		return;

	if (size[vParent] > size[uParent]) {
		parent[uParent] = vParent;
		size[vParent] += size[uParent];
	}
	else{
		parent[vParent] = uParent;
		size[uParent] += size[vParent];
	}
}
public:

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        map<int, vector<int>>right, left;
        vector<int>parent(n), size(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;

            left[stones[i][0]].push_back(i);
            right[stones[i][1]].push_back(i);
        }

        for(int i= 0; i < n; i++){
            for (int stoneIndex : left[stones[i][0]])
                Union(i, stoneIndex, parent, size);
            for (int stoneIndex : right[stones[i][1]])
                Union(i, stoneIndex, parent, size);
        }

        map<int, int>mp;

        for (int i = 0; i < n; i++) {
            mp[findOp(i, parent)]++;
        }

        int res = 0;
        for (auto entry : mp) {
            res += entry.second - 1;
        }
        return res;
    }
};