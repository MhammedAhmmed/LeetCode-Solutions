class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n1 = words1.size(), n2 = words2.size();

        vector<int> maxFreq(26, 0);

        for (string word : words2) {
            vector<int> freq(26, 0);

            int len = word.length();

            for (int i = 0; i < len; i++) {
                freq[word[i] - 'a']++;
            }

            for (int i = 0; i < 26; i++) {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }

        vector<string> res;

        for (string word : words1) {
            vector<int> freq(26, 0);
            int len = word.length();

            for (int i = 0; i < len; i++) {
                freq[word[i] - 'a']++;
            }

            bool universal = true;

            for (int i = 0; i < 26; i++) {
                if (freq[i] < maxFreq[i]) {
                    universal = false;
                    break;
                }
            }

            if (universal) {
                res.push_back(word);
            }
        }

        return res;
    }
};