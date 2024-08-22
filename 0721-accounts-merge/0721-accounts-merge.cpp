class Solution {
int findOp(int v, vector<int>& parent) {
	if (v == parent[v])
		return v;

	int result = findOp(parent[v], parent);

	parent[v] = result;

	return result;
}
void unionOp(int v, int u, vector<int>& parent, vector<int>& size) {
	int parentV = findOp(v, parent);
	int parentU = findOp(u, parent);

	if (parentV == parentU)
		return;

	if (size[parentV] > size[parentU]) {
		parent[parentU] = parentV;
		size[parentV] += size[parentU];
	}
	else {
		parent[parentV] = parentU;
		size[parentU] += size[parentV];
	}
}
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, int>mail;
        map<int, string>name;
        int n = accounts.size();

        vector<int>parent(10000, -1), size(10000, 1);
        
        int index = 1;
        for (int i = 0; i < n; i++) {
            unordered_set<int>parents;
            int len = accounts[i].size();
            for (int j = 1; j < len; j++) {
                if (mail[accounts[i][j]] == 0) {
                    mail[accounts[i][j]] = index;
                    parent[index] = index;
                    name[index++] = accounts[i][0];
                }
                parents.insert(mail[accounts[i][j]]);
            }
            if (parents.size() == 1)
                continue;

            int first = *parents.begin(), second;
            parents.erase(parents.begin());
            while (!parents.empty()) {
                second = *parents.begin();
                unionOp(first, second, parent, size);
                first = second;
                parents.erase(parents.begin());
            }
        }

        map<int, vector<string>>mp;
        for (int i = 1; i < index; i++) {
            if (parent[i] == i) {
                mp[i].push_back(name[i]);
            }	
        }
        for (auto entry : mail) {
            mp[findOp(entry.second, parent)].push_back(entry.first);
        }

        vector<vector<string>>res;
        for (auto enrty : mp) {
            res.push_back(enrty.second);
        }
        int len = res.size();
        for (int i = 0; i < len; i++) {
            sort(res[i].begin() + 1, res[i].end());
        }

        return res;
    }
};