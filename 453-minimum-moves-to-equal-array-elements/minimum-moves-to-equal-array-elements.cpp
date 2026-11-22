class Solution {
public:
    int minMoves(vector<int>& nums) {

        int minE = *min_element(nums.begin(), nums.end());
        int steps = 0;
        for(int i = 0; i < nums.size(); i++){
            steps += (nums[i] - minE);
        }
        return steps;
    }
};