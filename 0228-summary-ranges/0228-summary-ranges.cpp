class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> res;

        for (int i = 0; i < n; i++) {
            int start = nums[i];

            int to = nums[i];

            while (i + 1 < n && nums[i] == nums[i + 1] - 1) {
                to = nums[i + 1];
                i++;
            }

            string temp = to_string(start);

            if (start != to) {
                temp += "->";
                temp += to_string(to);
            }
            res.push_back(temp);
        }

        return res;
    }
};