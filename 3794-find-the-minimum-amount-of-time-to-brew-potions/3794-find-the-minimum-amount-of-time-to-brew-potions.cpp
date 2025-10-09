class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {

        int n = skill.size();
        int m = mana.size();
        vector<long long> pre(n, 0);

        for (int i = 0; i < m; i++) {
            long long start = pre[0];
            for (int j = 0; j < n - 1; j++) {
                int time = mana[i] * skill[j];
                start += time;
                if (start <= pre[j + 1]) {
                    start = pre[j + 1];
                }
            }
            long long finish = start + (mana[i] * skill[n - 1]);

            for (int j = n - 1; j >= 0; j--) {
                pre[j] = finish;
                finish -= (mana[i] * skill[j]);
            }
        }

        return pre[n - 1];
    }
};