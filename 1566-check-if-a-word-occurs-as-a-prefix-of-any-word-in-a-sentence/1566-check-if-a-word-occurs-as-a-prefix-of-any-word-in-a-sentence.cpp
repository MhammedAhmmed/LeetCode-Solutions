class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.size();
        int m = searchWord.size();

        int index = 1;
        for (int i = 0; i < n; i++) {
            if (sentence[i] == ' ') {
                continue;
            }

            if (n - i < m) {
                return -1;
            }

            bool findPref = true;
            for (int j = 0; j < m; j++) {
                if (sentence[i + j] != searchWord[j]) {
                    findPref = false;
                }
            }
            if (findPref) {
                return index;
            }
            while (i < n && sentence[i] != ' ') {
                i++;
            }

            index++;
        }

        return -1;
    }
};