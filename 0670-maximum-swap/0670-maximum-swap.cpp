class Solution {
public:
    int maximumSwap(int num) {
        string snum = to_string(num);

        string res = snum;

        int len = res.size();

        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                string temp = snum;

                char ch = temp[i];
                temp[i] = temp[j];
                temp[j] = ch;

                if (temp > res) {
                    res = temp;
                }
            }
        }

        return stoi(res);
    }
};