class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        vector<bool> take(n, false);

        int p1 = 0, p2 = 0;

        int chunks = 0;
        while (p2 < n) {
            take[arr[p2]] = 1;

            bool validChunk = true;
            for (int i = p1; i <= p2; i++) {
                if (!take[i]) {
                    validChunk = false;
                    break;
                }
            }

            if (validChunk) {
                chunks++;
                p1 = p2 + 1;
            }

            p2++;
        }

        return chunks;
    }
};