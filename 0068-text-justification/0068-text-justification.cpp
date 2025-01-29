class Solution {
public:
    string lastSentence(vector<string>& words, int l, int r, int sentenceLen,
                        int maxWidth) {

        string sentence = "";

        for (int i = l; i < r; i++) {
            sentence += words[i];
            sentence.push_back(' ');
        }
        sentence.pop_back();

        int addSolts = maxWidth - sentenceLen;

        while (addSolts--) {
            sentence.push_back(' ');
        }

        return sentence;
    }
    string createSentence(vector<string>& words, int l, int r, int sentenceLen,
                          int maxWidth) {
        int n = r - l;
        int emptySlots = n - 1 + (maxWidth - sentenceLen);

        string sentence = "";
        if (n == 1) {
            sentence = words[l];

            while (emptySlots--) {
                sentence.push_back(' ');
            }
            return sentence;
        }

        int k = emptySlots / (n - 1);
        int add = emptySlots % (n - 1);

        for (int i = l; i < r; i++) {
            sentence += words[i];

            if (i != r - 1) {
                int temp = k;
                while (temp--) {
                    sentence.push_back(' ');
                }

                if (add) {
                    sentence.push_back(' ');
                    add--;
                }
            }
        }

        return sentence;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        int index = 0;

        vector<string> res;
        while (index < n) {
            int l = index;

            int sentenceLen = words[index].size() + 1;
            index++;

            while (index < n && sentenceLen + words[index].size() <= maxWidth) {
                sentenceLen += words[index].size() + 1;
                index++;
            }
            int r = index;

            sentenceLen--;

            if (index == n) {
                res.push_back(lastSentence(words, l, r, sentenceLen, maxWidth));
            } else {
                res.push_back(
                    createSentence(words, l, r, sentenceLen, maxWidth));
            }
        }

        return res;
    }
};