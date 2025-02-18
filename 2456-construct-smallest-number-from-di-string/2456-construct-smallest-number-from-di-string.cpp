class Solution {
    bool findSmallest(string pattern, string &num, int index, int n, vector<bool>&take){
        if(index >= n + 1){
            return true;
        }

        int l, r;
        if(pattern[index - 1] == 'D'){
            l = 1;
            r = num[index - 1] - '0' - 1;
        }else{
            l = num[index - 1] - '0' + 1;
            r = n + 1;
        }

        for(int i = l; i <= r; i++){
            if(!take[i]){
                take[i] = true;
                num.push_back(char(i + '0'));

                if(findSmallest(pattern, num, index + 1, n, take)){
                    return true;
                }

                take[i] = false;
                num.pop_back();
            }
        }

        return false;
    }
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        vector<bool>take(n + 2, false);
        string num = "";

        for(int i = 1; i <= n + 1; i++){
            take[i] = true;
            num.push_back(char(i + '0'));

            if(findSmallest(pattern, num, 1, n, take)){
                return num;
            }

            take[i] = false;
            num.pop_back();
        }

        return num;
    }
};