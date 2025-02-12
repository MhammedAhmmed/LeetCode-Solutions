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
        if(same.size() <= 1){
            return -1;
        }

        int maxE = max(same[0], same[1]);
        int bMaxE = min(same[0], same[1]);

        for(int i = 2; i < same.size(); i++){
            if(same[i] >= maxE){
                bMaxE = maxE;
                maxE = same[i];
            }
            else if(same[i] > bMaxE){
                bMaxE = same[i];
            }
        }

        return maxE + bMaxE;
    }
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>>sameDigit;

        for(int num: nums){
            sameDigit[sumDigits(num)].push_back(num);
        }

        int res = -1;
        for(auto entry: sameDigit){
            res = max(res, maxPair(entry.second));
        }

        return res;
    }
};