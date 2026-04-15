class Solution {
    public int[] constructTransformedArray(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                int ind = (i + nums[i]) % n;
                res[i] = nums[ind];
            }else if(nums[i] < 0){
                int ind = ((i + nums[i]) % n + n) % n;
                res[i] = nums[ind];
            }else{
                res[i] = nums[i];
            }
        }
        return res;
    }
}