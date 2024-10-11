class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        int minArrival = INT_MAX, maxLeave = INT_MIN;

        unordered_multiset<int> msArrival;
        unordered_multiset<int> msleave;
        priority_queue<int, vector<int>, greater<int>> pq;
        map<int, vector<int>> leaveChair;

        for (int i = 0; i < n; i++) {
            pq.push(i);
            leaveChair[times[i][1]].push_back(times[i][0]);

            maxLeave = max(maxLeave, times[i][1]);
            minArrival = min(minArrival, times[i][0]);

            msArrival.insert(times[i][0]);
            msleave.insert(times[i][1]);
        }

        map<int, int> setChair;

        for (int i = minArrival; i <= maxLeave; i++) {
            if (msleave.find(i) != msleave.end()) {
                for (int arrival : leaveChair[i]) {
                    pq.push(setChair[arrival]);
                }
            }

            if (msArrival.find(i) != msArrival.end()) {
                if (i == times[targetFriend][0]) {
                    return pq.top();
                }
                setChair[i] = pq.top();
                pq.pop();
            }
        }
        return 0;
    }
};