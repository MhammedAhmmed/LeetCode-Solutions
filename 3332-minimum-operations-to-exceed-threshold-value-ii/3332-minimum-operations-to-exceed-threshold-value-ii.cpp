class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        priority_queue<long, vector<long>, greater<long>>pq;

        for(int num: nums){
            pq.push(num);
        }

        int numOfOp = 0;

        while(pq.size() > 1 && pq.top() < k){
            long x = pq.top();
            pq.pop();
            long y = pq.top();
            pq.pop();

            pq.push(min(x, y) * 2 + max(x, y));

            numOfOp++;
        }
        
        return numOfOp;
    }
};