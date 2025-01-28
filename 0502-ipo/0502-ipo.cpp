class Solution {
    static bool comparaotr(pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    }

public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {

        int n = profits.size();

        vector<pair<int, int>> profCap(n);

        for (int i = 0; i < n; i++) {
            profCap[i] = {profits[i], capital[i]};
        }

        sort(profCap.begin(), profCap.end(), comparaotr);

        priority_queue<pair<int, int>> pq;
        int index = 0;

        while (k--) {

            while (index < n && profCap[index].second <= w) {
                pq.push(profCap[index++]);
            }

            if (!pq.empty()) {
                w += pq.top().first;
                pq.pop();
            } else {
                break;
            }
        }

        return w;
    }
};