class Solution {
public:
    bool canAliceWin(int n) {
        int stones = 10;
        bool AliceTurn = true;

        while(n >= stones){
            n -= stones;
            stones--;
            AliceTurn = !AliceTurn;
        }

        return !AliceTurn;
    }
};