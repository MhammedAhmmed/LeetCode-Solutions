class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> lpq, rpq;
        int n = costs.size();

        for (int i = 0; i < candidates; i++) {
            lpq.push(costs[i]);
        }

        int rpqLen = min(n - candidates, candidates);
        for (int i = 0; i < rpqLen; i++) {
            rpq.push(costs[n - 1 - i]);
        }

        int pl = candidates - 1;
        int pr = n - rpqLen;

        long long res = 0;
        while (k--) {
            if (lpq.empty()) {
                res += rpq.top();
                rpq.pop();
            } else if (rpq.empty()) {
                res += lpq.top();
                lpq.pop();
            } else {
                if (lpq.top() <= rpq.top()) {
                    res += lpq.top();
                    lpq.pop();

                    if (pl + 1 < pr) {
                        pl++;
                        lpq.push(costs[pl]);
                    }
                } else {
                    res += rpq.top();
                    rpq.pop();

                    if (pr - 1 > pl) {
                        pr--;
                        rpq.push(costs[pr]);
                    }
                }
            }
        }
        return res;
    }
};