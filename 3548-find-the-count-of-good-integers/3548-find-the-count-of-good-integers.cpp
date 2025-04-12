class Solution {
public:
    unordered_set<string> nums;
    void createPalindrom(int n, int k, int index, string num) {

        if (index > (n / 2)) {
            long long numl = stoll(num);
            if (numl % k == 0) {
                string temp = num;
                sort(temp.begin(), temp.end());
                nums.insert(temp);
            }
            return;
        }

        int d = 0;
        if (index == 0) {
            d++;
        }

        for (; d < 10; d++) {
            num[index] = num[n - index - 1] = (d + '0');
            createPalindrom(n, k, index + 1, num);
        }
    }

    long long countGoodIntegers(int n, int k) {
        vector<int> fact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = i * fact[i - 1];
        }

        string num = "";
        for (int i = 0; i < n; i++) {
            num.push_back('0');
        }

        createPalindrom(n, k, 0, num);

        long long res = 0;

        for (string s : nums) {
            vector<int> freq(10, 0);

            int sCount = 0;
            for (char ch : s) {
                freq[ch - '0']++;
            }

            long long rep = 1;
            for (int i = 0; i < 10; i++) {
                rep *= fact[freq[i]];
            }
            sCount += (fact[n] / rep);

            if (freq[0]) {
                rep /= freq[0];

                sCount -= (fact[n - 1] / rep);
            }

            res += sCount;
        }
        return res;
    }
};