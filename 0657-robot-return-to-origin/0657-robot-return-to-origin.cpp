class Solution {
public:
    bool judgeCircle(string moves) {

        int v = 0, h = 0;
        for(char ch: moves){
            if(ch == 'R'){
                h++;
            }
            if(ch == 'L'){
                h--;
            }
            if(ch == 'U'){
                v++;
            }
            if(ch == 'D'){
                v--;
            }
        }
        return (h == 0 && v == 0);
    }
};