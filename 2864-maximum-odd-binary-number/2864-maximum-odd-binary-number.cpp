class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string t = "";
        int ones = 0, zeros = s.size();

        for (char ch : s)
            if (ch == '1')
                ones++;
        zeros -= ones;

        while(ones-- != 1)
            t.push_back('1');

        while (zeros--)
            t.push_back('0');

        t.push_back('1');

        return t;
    }
};