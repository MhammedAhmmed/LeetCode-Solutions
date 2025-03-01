class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n - 1; i++){
            if(nums[i] == nums[i + 1]){
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        int p1 = 0, p2 = 0;

        while(p2 < n){
            if(nums[p2] != 0){
                while(p1 < p2 && nums[p1] != 0){
                    p1++;
                }

                int temp = nums[p2];
                nums[p2] = 0;
                nums[p1] = temp;
            }
            p2++;
        }

        return nums;   
    }
};