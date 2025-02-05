class Solution {
    vector<int> orginal, shuffleArr;

public:
    Solution(vector<int>& nums) {
        orginal = shuffleArr = nums;
        srand(time(0));
    }

    vector<int> reset() { return orginal; }

    vector<int> shuffle() {
        int n = shuffleArr.size();

        for (int i = 0; i < n; i++) {
            int p1 = rand() % n;
            int p2 = rand() % n;

            swap(shuffleArr[p1], shuffleArr[p2]);
        }
        return shuffleArr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */