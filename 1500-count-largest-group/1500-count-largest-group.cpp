class Solution {
    int sumDigits(int num) {

        int sum = 0;

        while (num) {
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }

public:
    int countLargestGroup(int n) {

        unordered_map<int, int> freq;

        int maxSize = 0;

        for (int i = 1; i <= n; i++) {

            int sum = sumDigits(i);
            freq[sum]++;

            maxSize = max(maxSize, freq[sum]);
        }

        int res = 0;
        for (auto entry : freq) {
            if (entry.second == maxSize) {
                res++;
            }
        }

        return res;
    }
};