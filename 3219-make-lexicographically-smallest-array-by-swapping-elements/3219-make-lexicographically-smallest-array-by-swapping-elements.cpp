class Solution {
    void setRes(int l, int r, vector<pair<int, int>>& numIndex,
                vector<int>& nums) {
        vector<int> index(r - l);

        for (int i = l; i < r; i++) {
            index[i - l] = numIndex[i].second;
        }
        sort(index.begin(), index.end());

        for (int i = l; i < r; i++) {
            nums[index[i - l]] = numIndex[i].first;
        }
    }
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int, int>> numIndex(n);

        for (int i = 0; i < n; i++) {
            numIndex[i] = {nums[i], i};
        }

        sort(numIndex.begin(), numIndex.end());

        for (int i = 0; i < n; i++) {
            int j = i + 1;

            while (j < n &&
                   numIndex[j].first - numIndex[j - 1].first <= limit) {
                j++;
            }

            setRes(i, j, numIndex, nums);

            i = j - 1;
        }

        return nums;
    }
};