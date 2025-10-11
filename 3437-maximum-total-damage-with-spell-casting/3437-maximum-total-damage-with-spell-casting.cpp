class Solution {
    long long maxSubDamage(vector<int>& sub, unordered_map<int, int>& freq) {

        int n = sub.size();
        vector<long long> dp(n);
        vector<long long> maxTellNow(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int index = i + 1;
            while (index < n && sub[index] <= sub[i] + 2) {
                index++;
            }

            long long maxDamage = 0;
            if (index < n) {
                maxDamage = maxTellNow[index];
            }
            /*while (index < n) {
                maxDamage = max(maxDamage, dp[index]);
                index++;
            }*/
            dp[i] = (long long)sub[i] * freq[sub[i]] + maxDamage;
            maxTellNow[i] = max(dp[i], maxTellNow[i + 1]);
        }

        long long res = *max_element(dp.begin(), dp.end());
        return res;
    }

public:
    long long maximumTotalDamage(vector<int>& power) {

        unordered_map<int, int> freq;
        int n = power.size();
        vector<int> dist;

        for (int i = 0; i < n; i++) {
            if (freq[power[i]] == 0) {
                dist.push_back(power[i]);
            }
            freq[power[i]]++;
        }

        sort(dist.begin(), dist.end());
        vector<int> sub{dist[0]};
        int len = dist.size();
        long long res = 0;
        for (int i = 1; i < len; i++) {
            if (dist[i] > dist[i - 1] + 2) {
                res += maxSubDamage(sub, freq);
                sub.clear();
            }
            sub.push_back(dist[i]);
        }
        res += maxSubDamage(sub, freq);
        return res;
    }
};