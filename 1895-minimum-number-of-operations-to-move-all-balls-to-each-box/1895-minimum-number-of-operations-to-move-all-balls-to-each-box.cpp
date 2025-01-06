class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();

        int moves = 0;
        int rightOnes = 0, leftOnes = 0;
        for (int i = 1; i < n; i++) {
            if (boxes[i] == '1') {
                moves += i;
                rightOnes++;
            }
        }
        if (boxes[0] == '1') {
            leftOnes++;
        }

        vector<int> res(n);
        res[0] = moves;

        for (int i = 1; i < n; i++) {
            moves += leftOnes;
            moves -= rightOnes;

            res[i] = moves;

            if (boxes[i] == '1') {
                rightOnes--;
                leftOnes++;
            }
        }

        return res;
    }
};