class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        int n = nums.size();

        vector<pair<int, int>> parityIntervals;

        int p1 = 0, p2 = 1;

        while (p2 < n) {
            if (!((nums[p2] ^ nums[p2 - 1]) & 1)) {
                parityIntervals.push_back({p1, p2 - 1});
                p1 = p2;
            }
            p2++;
        }
        parityIntervals.push_back({p1, p2 - 1});

        int quLen = queries.size();
        int pLen = parityIntervals.size();

        vector<bool> res(quLen);
        ;
        for (int i = 0; i < quLen; i++) {
            int l = 0, r = pLen - 1;
            int mid;
            bool special = false;

            while (l <= r) {
                mid = (l + r) / 2;

                if (queries[i][0] < parityIntervals[mid].first) {
                    r = mid - 1;
                } else if (queries[i][0] > parityIntervals[mid].second) {
                    l = mid + 1;
                } else {
                    if (queries[i][1] <= parityIntervals[mid].second) {
                        special = true;
                    }
                    break;
                }
            }
            res[i] = special;
        }
        return res;
    }
};