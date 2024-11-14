class Solution {
    int numOfStore(vector<int>& quantities, int x) {
        int n = 0;
        for (int quantitie : quantities) {
            n += ((quantitie + x - 1) / x);
        }

        return n;
    }

public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1, r = *max_element(quantities.begin(), quantities.end());

        int mid, res = r;

        while (l <= r) {
            mid = (l + r) / 2;

            int k = numOfStore(quantities, mid);
            if (k <= n) {
                res = min(res, mid);

                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return res;
    }
};