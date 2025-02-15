class Solution {
    bool validNum(int num, string square, int sum, int index){
        if(index >= square.size()){
            return sum == num;
        }

        int len = square.size();

        for(int i = index; i < len; i++){
            
            int substrNum = stoi(square.substr(index, i - index + 1));
            sum += substrNum;

            if(validNum(num, square, sum, i + 1)){
                return true;
            }

            sum -= substrNum;
        }

        return false;
    }
public:
    int punishmentNumber(int n) {
        int pun = 1;

        for(int i = 9; i <= n; i++){
            if(validNum(i, to_string(i * i), 0, 0)){
                pun += (i * i);
            }
        }
        
        return pun;
    }
};