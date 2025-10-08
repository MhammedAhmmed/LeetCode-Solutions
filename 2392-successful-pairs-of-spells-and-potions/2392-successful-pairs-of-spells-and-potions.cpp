class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {

        sort(potions.begin(), potions.end());

        int n = spells.size();
        int m = potions.size();
        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            int l = 0, r = m - 1, mid;
            int index = m;
            while (l <= r) {
                mid = (l + r) / 2;
                if ((long long)spells[i] * potions[mid] < success) {
                    l = mid + 1;
                } else {
                    index = mid;
                    r = mid - 1;
                }
            }
            res[i] = m - index;
            cout << res[i] << " ";
        }

        return res;
    }
};