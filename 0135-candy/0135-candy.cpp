class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> candies(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        for (int i = 0; i < n; i++) {
            pq.push({ratings[i], i});
        }

        while (!pq.empty()) {
            int rate = pq.top().first;
            int index = pq.top().second;

            pq.pop();

            int minCandies = 1;

            if (index != 0 && ratings[index - 1] < rate) {
                minCandies = candies[index - 1] + 1;
            }

            if (index != n - 1 && ratings[index + 1] < rate) {
                minCandies = max(minCandies, candies[index + 1] + 1);
            }

            candies[index] = minCandies;
        }

        int res = 0;
        for (int x : candies) {
            res += x;
        }
        return res;
    }
};