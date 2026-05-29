class Solution {
public:
    int minElement(vector<int>& nums) {
        int minSum = INT_MAX;

        for(int x : nums){
            int sum = 0;
            while(x){
                sum += x%10;
                x /= 10;
            }
            minSum = min(minSum, sum);
        }
        return minSum;
    }
};