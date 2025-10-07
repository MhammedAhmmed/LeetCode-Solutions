class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {

        set<int> empty;
        unordered_map<int, int> mp;

        int n = rains.size();
        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                empty.insert(i);
            } else {
                res[i] = -1;
                if (mp.find(rains[i]) == mp.end()) {
                    mp[rains[i]] = i;
                } else {
                    int preIndex = mp[rains[i]];

                    auto pt = empty.lower_bound(preIndex);
                    if (pt == empty.end()) {
                        return {};
                    }

                    int emptyIndex = *pt;
                    res[emptyIndex] = rains[i];

                    empty.erase(emptyIndex);
                    mp[rains[i]] = i;
                }
            }
        }

        for (auto index : empty) {
            res[index] = 1;
        }

        return res;
    }
};