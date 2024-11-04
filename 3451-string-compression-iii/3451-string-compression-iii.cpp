class Solution {
public:
    string compressedString(string word) {
        int len = word.size();
        int i = 0;

        string res = "";

        while (i < len) {
            char ch = word[i];
            int count = 0;

            while (i < len && word[i] == ch) {
                count++;
                i++;

                if (count == 9)
                    break;
            }
            res.push_back((char)(count + '0'));
            res.push_back(ch);
        }

        return res;
    }
};