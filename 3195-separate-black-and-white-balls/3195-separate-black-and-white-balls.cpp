class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        int numOfOnes = 0;

        int p = n - 1;

        long long res = 0;
        while (p >= 0) {
            if (s[p] == '1') {
                res += ((n - p - 1) - numOfOnes);
                numOfOnes++;
            }
            p--;
        }

        return res;
    }
};