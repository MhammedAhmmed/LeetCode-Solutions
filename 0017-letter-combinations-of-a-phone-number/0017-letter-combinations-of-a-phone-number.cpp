class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        map<char, string>mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        if (digits.size() == 0)
            return res;

        int n = 1;
        for (int i = 0;i < digits.size(); i++)
            n *= mp[digits[i]].size();

        res = vector<string>(n);
        int y = n;

        for (int i = 0;i < digits.size(); i++) {
            int x = mp[digits[i]].size();

            y /= x;
            
            int q = 0;

            for (int j = 0; j < n; j++) {
                if (j % y == 0 && j != 0)
                    q = (q + 1) % x;
                res[j].push_back(mp[digits[i]][q]);
            }
        }
        return res;	
        
    }
};