class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();

        int distA = 0, after = 0, before = 0, distB = 0;

        for (int i = 0; i < n; i++) {
            if (boxes[i] == '1') {
                after++;
                distA += (i + 1);
            }
        }

        vector<int>res(n, 0);

        for (int i = 0; i < n; i++) {
            int dist = distA - after + distB;
            res[i] = dist;

            distA -= after;
            if (boxes[i] == '1') {
                before++;
                after--;
            }
            distB += (before);
        }

        return res;
    }
};