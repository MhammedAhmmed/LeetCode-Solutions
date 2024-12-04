class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size();
        int p1 = 0, p2 = 0;

        while (p1 < n1 && p2 < n2) {
            if (str1[p1] == 'z') {
                if (str2[p2] == str1[p1] || str2[p2] == 'a') {
                    p2++;
                }
            } else if (str2[p2] == str1[p1] || str2[p2] == char(str1[p1] + 1)) {
                p2++;
            }
            p1++;
        }

        return p2 == n2;
    }
};