class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        }

        double halfPow = myPow(x, n / 2);

        double res = halfPow * halfPow;

        if ((abs(n) & 1) == 1) {
            if (n > 0) {
                res *= x;
            } else {
                res *= (1.0 / x);
            }
        }

        return res;
    }
};