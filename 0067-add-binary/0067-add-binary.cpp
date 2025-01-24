class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.size(), n2 = b.size(), carr = 0;

        int diff = abs(n1 - n2);
        if (n1 < n2) {
            while (diff--) {
                a = '0' + a;
            }
        } else if (n2 < n1) {
            while (diff--) {
                b = '0' + b;
            }
        }

        string res = "";
        int len = max(n1, n2);
        for (int i = len - 1; i >= 0; i--) {
            int aNum = a[i] - '0';
            int bNum = b[i] - '0';

            if (aNum + bNum + carr == 3) {
                res.push_back('1');
            } else if (aNum + bNum + carr == 2) {
                res.push_back('0');
                carr = 1;
            } else {
                res.push_back(char(aNum + bNum + carr + '0'));
                carr = 0;
            }
        }

        if (carr == 1) {
            res.push_back('1');
        }

        reverse(res.begin(), res.end());

        return res;
    }
};