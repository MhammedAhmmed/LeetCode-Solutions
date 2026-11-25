class Solution {
public:
    int minMoves2(vector<int>& nums) {

        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());

        int mid = (l + r) / 2;
        long long steps = 0;
        for(int num: nums){
            steps += abs(mid - num);
        }

        while(l <= r){
            mid = (l + r) / 2;
            int less = 0, greater = 0;
            long long tempSteps = 0;
            for(int num : nums){
                if(num < mid){
                    less++;
                }else if(num > mid){
                    greater++;
                }
                tempSteps += abs(mid - num);
            }
            steps = min(steps, tempSteps);
            if(less == greater){
                return steps;
            }
            if(less > greater){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return steps;
    }
};