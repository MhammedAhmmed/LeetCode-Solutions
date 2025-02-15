class Solution {
    bool validNum(int i, int num, int sum){
        if(num == 0){
            return sum == i;
        }

        int x = 1;
        int sufNum = 0;
        while(num){
            sufNum += (x * (num % 10));
            num /= 10;

            sum += sufNum;
            if(validNum(i, num, sum)){
                return true;
            }
            sum -= sufNum;

            x *= 10;
        }

        return false;
    }
public:
    int punishmentNumber(int n) {
        int pun = 1;

        for(int i = 9; i <= n; i++){
            if(validNum(i, i * i, 0)){
                pun += (i * i);
            }
        }
        
        return pun;
    }
};