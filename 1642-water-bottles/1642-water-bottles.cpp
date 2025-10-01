class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;
        int empty = numBottles;

        while(empty >= numExchange){
            int drink = (empty / numExchange); 
            empty = (empty % numExchange);
            empty += drink;
            res += drink;
        }
        
        return res;
    }
};