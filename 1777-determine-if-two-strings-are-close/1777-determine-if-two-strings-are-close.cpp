class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> freq1(26, 0), freq2(26, 0);

        for (char ch : word1) {
            freq1[ch - 'a']++;
        }
        for (char ch : word2) {
            freq2[ch - 'a']++;
        }

        int charNum = 26;
        for (int i = 0; i < charNum; i++) {
            if ((freq1[i] && !freq2[i]) || (!freq1[i] && freq2[i])) {
                return false;
            }
        }

        map<int, int> freqFreq;

        for (int i = 0; i < charNum; i++) {
            if (freq2[i]) {
                freqFreq[freq2[i]]++;
            }
        }

        for (int i = 0; i < charNum; i++) {
            if (freq1[i]) {
                if (freqFreq[freq1[i]] == 0) {
                    return false;
                }

                freqFreq[freq1[i]]--;
            }
        }

        return true;
    }
};