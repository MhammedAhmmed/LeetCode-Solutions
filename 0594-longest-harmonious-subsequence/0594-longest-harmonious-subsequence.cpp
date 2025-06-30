class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        int maxLen = 0;
        int prevNum = freq.begin()->first, prevFreq = freq.begin()->second;

        for (auto entry : freq) {
            if (entry.first - prevNum == 1) {
                maxLen = max(maxLen, prevFreq + entry.second);
            }
            prevNum = entry.first;
            prevFreq = entry.second;
        }
        return maxLen;
    }
};