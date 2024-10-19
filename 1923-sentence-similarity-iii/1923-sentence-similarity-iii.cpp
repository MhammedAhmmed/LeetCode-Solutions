class Solution {
    vector<string> splitString(string sentence) {
        int n1 = sentence.size();

        vector<string> words;

        for (int i = 0; i < n1; i++) {
            if (sentence[i] != ' ') {
                string temp = "";

                while (i < n1 && sentence[i] != ' ') {
                    temp.push_back(sentence[i]);
                    i++;
                }

                words.push_back(temp);
            }
        }

        return words;
    }

    bool similar(vector<string>& v1, int n1, vector<string>& v2, int n2) {

        int p1 = 0;
        int i = 0;
        while (p1 < n1 && v1[p1] == v2[i]) {
            p1++;
            i++;
        }

        int p2 = n1 - 1;
        i = n2 - 1;
        while (p2 >= 0 && v1[p2] == v2[i]) {
            p2--;
            i--;
        }

        return p1 > p2;
    }

public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> words1 = splitString(sentence1);
        vector<string> words2 = splitString(sentence2);

        int n1 = words1.size();
        int n2 = words2.size();

        if (n1 == n2) {
            return sentence1 == sentence2;
        }

        if (n1 < n2) {
            return similar(words1, n1, words2, n2);
        }

        return similar(words2, n2, words1, n1);
    }
};