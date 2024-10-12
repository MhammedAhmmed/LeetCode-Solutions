class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> freq;
        for (char ch : magazine) {
            freq[ch]++;
        }

        for (char ch : ransomNote) {
            if (!freq[ch])
                return false;
            freq[ch]--;
        }

        return true;
    }
};