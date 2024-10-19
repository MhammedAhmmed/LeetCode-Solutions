class Solution {
    string invert(string s) {
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '0')
                s[i] = '1';
            else
                s[i] = '0';
        }

        return s;
    }

public:
    char findKthBit(int n, int k) {
        n--;
        string s = "0";

        while (n--) {
            string temp = invert(s);
            reverse(temp.begin(), temp.end());

            s = s + "1" + temp;
        }

        return s[k - 1];
    }
};