class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();

        vector<int> prefa(n, 0), prefb(n, 0), prefc(n, 0);

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') {
                prefa[i]++;
            } else if (s[i] == 'b') {
                prefb[i]++;
            } else {
                prefc[i]++;
            }
        }
        for (int i = 1; i < n; i++) {
            prefa[i] += prefa[i - 1];
            prefb[i] += prefb[i - 1];
            prefc[i] += prefc[i - 1];
        }

        if (prefa[n - 1] < k || prefb[n - 1] < k || prefc[n - 1] < k) {
            return -1;
        }

        if (k == 0)
            return 0;

        map<char, int> mp;
        mp['a'] = mp['b'] = mp['c'] = 0;

        int res = n;
        for (int j = n; j > 0; j--) {

            int l = 0, r = j - 1, mid, minL = j - 1;

            if (mp['a'] >= k && mp['b'] >= k && mp['c'] >= k) {
                res = min(res, n - j);
                continue;
            }

            while (l <= r) {
                mid = (l + r) / 2;

                if (prefa[mid] + mp['a'] >= k && prefb[mid] + mp['b'] >= k &&
                    prefc[mid] + mp['c'] >= k) {
                    minL = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            res = min(res, minL + 1 + n - j);

            cout << minL + 1 + n - j << " " << minL << endl;
            mp[s[j - 1]]++;
        }

        return res;
    }
};