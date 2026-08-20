class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {

        int l1 = nums[0], l2 = nums[1];
        int arr1Len = 1, arr2Len = 1;
        int n = nums.size();
        for(int i = 2; i < n; i++){
            if(l1 > l2){
                l1 = nums[i];
                arr1Len++;
            }else{
                l2 = nums[i];
                arr2Len++;
            }
        }

        vector<int>res(n);
        res[0] = nums[0];
        res[arr1Len] = nums[1];
        l1 = nums[0], l2 = nums[1];
        int l1i = 1, l2i = arr1Len + 1;
         for(int i = 2; i < n; i++){
            if(l1 > l2){
                l1 = nums[i];
                res[l1i++] = nums[i];
            }else{
                l2 = nums[i];
                res[l2i++] = nums[i];
            }
        }
        return res;
    }
};