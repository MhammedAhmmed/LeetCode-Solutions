class Solution {
    vector<int> seive(int n) {
        vector<bool> isPrime(n + 1, true);

        isPrime[0] = isPrime[1] = false;
        vector<int> primes;
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        for (int i = 2; i <= n; i++) {
            if (isPrime[i])
                primes.push_back(i);
        }
        return primes;
    }

public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> primes = seive(1000);

        int n = nums.size(), plen = primes.size();

        int prev = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] > prev) {
                int maxPrime = 0;
                for (int j = 0; j < plen; j++) {
                    if (nums[i] - primes[j] > prev) {
                        maxPrime = primes[j];
                    }
                }
                nums[i] -= maxPrime;
                prev = nums[i];
            } else {
                return false;
            }
        }

        return true;
    }
};