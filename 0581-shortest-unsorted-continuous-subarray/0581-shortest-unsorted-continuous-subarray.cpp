class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
       
        vector<int>temp = nums;

        sort(temp.begin(), temp.end());

        int n = nums.size();
        int p1 = 0, p2 = n - 1;

        while(p1 < n && nums[p1] == temp[p1]){
            p1++;
        }
        
        while(p2 >= 0 && nums[p2] == temp[p2]){
            p2--;
        }

        if(p1 > p2){
            return 0;
        }

        return p2 - p1 + 1;
    }
};