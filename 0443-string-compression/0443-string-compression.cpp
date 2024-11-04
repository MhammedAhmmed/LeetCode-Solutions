class Solution {
public:
    int compress(vector<char>& chars) {
        int len = chars.size();

        int i = 0;
        int res = 0;

        int index = 0;
        while (i < len) {
            int count = 0;
            char ch = chars[i];
            while (i < len && chars[i] == ch) {
                count++;
                i++;
            }
            res++;
            chars[index++] = ch;
            if (count > 1) {
                string countStr = to_string(count);
                res = res + countStr.size();
                int countlen = countStr.size(), j = 0;

                while (countlen--) {
                    chars[index++] = countStr[j++];
                }
            }
        }

        return res;
    }
};