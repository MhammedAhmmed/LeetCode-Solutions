class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int maxSub = 0;
        int prefSum = 0;
        for(int num: nums){
            prefSum += num;

            if(prefSum < 0){
                prefSum = 0;
            }

            maxSub = max(maxSub, prefSum);
        }
        
        int minSub = 0;
        prefSum = 0;
        for(int num: nums){
            prefSum += num;

            if(prefSum > 0){
                prefSum = 0;
            }

            minSub = min(minSub, prefSum);
        }

        return max(maxSub, minSub * -1);
    }
};