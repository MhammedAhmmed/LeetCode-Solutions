class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int mod = 1000000007;

        vector<pair<int, int>>v(n);

        for (int i = 0; i < n; i++) {
            v[i] = { efficiency[i], i };
        }
        sort(v.begin(), v.end(), greater<pair<int,int>>());

        unsigned long long sum = 0, minE = v[k - 1].first, res = 0;
        priority_queue<int, vector<int>, greater<int>>pq;
        for (int i = 0; i < k; i++) {
            pq.push(speed[v[i].second]);
            sum = (sum + speed[v[i].second]);

            res = max(res, sum * v[i].first);
        }

        for (int i = k; i < n; i++) {
            sum = (sum - pq.top());
            pq.pop();

            minE = v[i].first;
            pq.push(speed[v[i].second]);
            sum = (sum + speed[v[i].second]);

            res = max(res, sum * minE);
        }
        return res % mod;
    }
};