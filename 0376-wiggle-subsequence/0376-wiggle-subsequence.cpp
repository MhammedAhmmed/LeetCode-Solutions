class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        bool pos = false;

        for(int i = 1; i < n; i++){
            int diff = nums[i] - nums[i - 1]; 

            if(diff == 0){
                continue;
            }

            if(res == 0){
                res++;
                if(diff > 0){
                    pos = true;
                }
            }
            else{
                if(diff > 0){
                    if(!pos){
                        res++;
                        pos = true;
                    }
                }
                else{
                    if(pos){
                        res++;
                        pos = false;
                    }
                }
            }
        }

        return res + 1;
    }
};