class Solution {
public:
    long long nc2(long long n) { return (n * (n - 1)) / 2; }
    long long countGood(vector<int>& nums, int k) {

        long long count = 0, res = 0;
        int n = nums.size();

        unordered_map<int, int> freq;
        int p1 = 0, p2 = 0;

        while (p2 < n) {
            count -= nc2(freq[nums[p2]]);
            freq[nums[p2]]++;
            count += nc2(freq[nums[p2]]);

            while (count >= k) {
                res += (n - p2);

                count -= nc2(freq[nums[p1]]);
                freq[nums[p1]]--;
                count += nc2(freq[nums[p1]]);
                p1++;
            }

            p2++;
        }

        return res;
    }
};