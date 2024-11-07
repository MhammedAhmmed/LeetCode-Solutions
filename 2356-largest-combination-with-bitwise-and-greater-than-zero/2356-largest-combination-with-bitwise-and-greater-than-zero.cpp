class Solution {
    void incFreq(vector<int>& bitFreq, int num) {

        int index = 0;

        while (num) {
            if (num & 1) {
                bitFreq[index]++;
            }
            index++;
            num >>= 1;
        }
    }
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bitFreq(32, 0);

        for (auto candidate : candidates) {
            incFreq(bitFreq, candidate);
        }

        return *max_element(bitFreq.begin(), bitFreq.end());
    }
};