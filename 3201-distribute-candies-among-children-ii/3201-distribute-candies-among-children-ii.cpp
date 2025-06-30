class Solution {
    public:
    long long distributeCandies(int n, int limit) {

        int maxVal = min(n, limit);
        int minVal = max(0, n - 2 * maxVal);

        long long res = 0;
        for(int i = minVal; i <= maxVal; i++){
            int rest = n - i;

            int maxS = min(rest, limit);
            int minS = max(0, rest - maxS);

            res += (maxS - minS + 1);
        }

        return res;
    }
};