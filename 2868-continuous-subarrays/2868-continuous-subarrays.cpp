class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        multiset<int> ms;

        int n = nums.size();

        int minE, maxE;

        long long res = 0;

        int p1 = 0, p2 = 0;
        int prevP1 = -1, prevP2 = -1;

        while (p2 < n) {
            ms.insert(nums[p2]);

            minE = *ms.begin();
            maxE = *ms.rbegin();

            if (maxE - minE > 2) {
                long long len = p2 - p1;

                res += (len * (len + 1)) / 2;

                if (p1 <= prevP2) {
                    len = prevP2 - p1 + 1;

                    res -= (len * (len + 1)) / 2;
                }

                prevP1 = p1;
                prevP2 = p2 - 1;

                while (maxE - minE > 2) {
                    ms.erase(ms.find(nums[p1]));

                    minE = *ms.begin();
                    maxE = *ms.rbegin();

                    p1++;
                }
            }
            p2++;
        }

        long long len = p2 - p1;

        res += (len * (len + 1)) / 2;

        if (p1 <= prevP2) {
            len = prevP2 - p1 + 1;

            res -= (len * (len + 1)) / 2;
        }

        return res;
    }
};