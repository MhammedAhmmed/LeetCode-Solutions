class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string>pre;

        for(int x: arr2){
            string snum = to_string(x);
            while(snum.size()){
                pre.insert(snum);
                snum.pop_back();
            }
        }
        int res = 0;
        for(int x :arr1){
            string snum = to_string(x);
            while(snum.size()){
                if(pre.find(snum) != pre.end()){
                    int len = snum.size();
                    res = max(res, len);
                    break;
                }
                snum.pop_back();
            }
        }
        return res;
    }
};