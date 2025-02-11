class Solution {
public:
    string removeOccurrences(string s, string part) {
        int len = part.size();
        string temp = "";

        for(char ch: s){
            temp.push_back(ch);

            if(temp.size() >= len){
                if(temp.substr(temp.size()-len, len) == part){
                    for(int i = 0; i < len; i++){
                        temp.pop_back();
                    }
                }
            }
        }

        return temp;
    }
};