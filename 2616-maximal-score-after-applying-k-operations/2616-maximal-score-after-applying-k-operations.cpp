class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for (int num : nums) {
            pq.push(num);
        }

        long long score = 0;

        while (k--) {
            score += pq.top();

            pq.push((pq.top() + 2) / 3);
            pq.pop();
        }

        return score;
    }
};