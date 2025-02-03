class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();

        vector<long long>temp(n);
        for(int i = 0; i < n; i++){
            temp[i] = nums[i];
            sum += temp[i];
        }

        for(int i = n - 1; i > 0; i--){
            long long avg = (sum + i) / (i + 1);

            if(temp[i] >= avg){
                temp[i - 1] += (temp[i] - avg);
                temp[i] = avg;
            }

            sum -= temp[i]; 
        }

        int maxVal = 0;
        for(int num: temp){
            maxVal = max(maxVal, num);
        }
        
        return maxVal;
    }
};