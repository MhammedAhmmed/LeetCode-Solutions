class Solution {
    void findNumbers(vector<int>& freq, vector<int>& res, int index, int num) {
        if (index == 3) {
            res.push_back(num / 10);
            return;
        }

        for (int i = 0; i < 10; i++) {
            if (i == 0 && index == 0) {
                continue;
            }
            if ((i & 1) && index == 2) {
                continue;
            }

            if (freq[i]) {
                freq[i]--;
                num += i;
                findNumbers(freq, res, index + 1, num * 10);
                num -= i;
                freq[i]++;
            }
        }
    }

public:
    vector<int> findEvenNumbers(vector<int>& digits) {

        vector<int> freq(10, 0);
        for (int digit : digits) {
            freq[digit]++;
        }

        vector<int> res;
        findNumbers(freq, res, 0, 0);
        return res;
    }
};