class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        int n = gifts.size();

        for(int x: gifts){
            pq.push(x);
        }

        while(k--){
            int maxTop = pq.top();
            pq.pop();
            pq.push(sqrt(maxTop));
        }

        long long res = 0;
        while(!pq.empty()){
            res += pq.top();
            pq.pop();
        }

        return res;
    }
};