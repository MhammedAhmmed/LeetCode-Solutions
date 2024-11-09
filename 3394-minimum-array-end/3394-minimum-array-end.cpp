class Solution {
public:
    long long minEnd(int n, int x) {

        long long i = x;
        while (n != 1) {
            i = (i + 1) | x;
            n--;
        }

        return i;
    }
};