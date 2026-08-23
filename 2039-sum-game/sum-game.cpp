class Solution {
public:
    bool sumGame(string num) {

        int n = num.size();
        int lq = 0, rq = 0, lsum = 0, rsum = 0;
        for(int i = 0; i < n / 2; i++){
            if(num[i] == '?'){
                lq++;
            }else{
                lsum += (num[i] - '0');
            }
        }
        for(int i = n / 2; i < n; i++){
            if(num[i] == '?'){
                rq++;
            }else{
                rsum += (num[i] - '0');
            }
        }
        int alice = 0, bob = 0;
        if((lq + rq) & 1){
            alice = (lq + rq) / 2 + 1;
            bob = (lq + rq) / 2;
        }else{
            alice = bob = (lq + rq) / 2;
        }
        int left = lsum, right = rsum;
        if(lq >= alice){
            left += (alice * 9);
            right += (rq * 9);
        }else{
            left += (lq * 9);
            right += (bob * 9);
        }
        if(left != right){
            return true;
        }

        left = lsum, right = rsum;
        if(rq >= alice){
            right += (alice * 9);
            left += (lq * 9);
        }else{
            right += (rq * 9);
            left += (bob * 9);
        }
        if(left != right){
            return true;
        }
     return false;   
    }
};