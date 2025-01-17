class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int sum = 0;

        for(int x : derived){
            sum ^= x;
        }
        
        return sum == 0;
    }
};