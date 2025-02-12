class Solution {
    int sumDigits(int num){
        int sum = 0;

        while(num){
            sum += (num % 10);
            num /= 10;
        }

        return sum;
    }
    int maxPair(vector<int>&same){
       sort(same.begin(), same.end());
       int len = same.size();
       return same[len - 1] + same[len - 2];
    }
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>>sameDigit;

        for(int num: nums){
            sameDigit[sumDigits(num)].push_back(num);
        }

        int res = -1;
        for(auto entry: sameDigit){
            if(entry.second.size() > 1){
                res = max(res, maxPair(entry.second));
            }
        }

        return res;
    }
};