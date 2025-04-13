class Solution {
public:
    long long power(int x, long long n, int mod) {
        if (n == 0) {
            return 1;
        }

        long long powerRes = power(x, n / 2, mod);

        powerRes %= mod;
        powerRes *= powerRes;
        powerRes %= mod;

        if (n & 1) {
            powerRes *= x;
            powerRes %= mod;
        }
        return powerRes;
    }
    int countGoodNumbers(long long n) {

        int mod = 1e9 + 7;
        int EVENS = 5;
        int PRIMES = 4;

        long long res = power(EVENS, n / 2, mod) * power(PRIMES, n / 2, mod);

        res %= mod;

        if (n & 1) {
            res *= EVENS;
        }

        return res % mod;
    }
};