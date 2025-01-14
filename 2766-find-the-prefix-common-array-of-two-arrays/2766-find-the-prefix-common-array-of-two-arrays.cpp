class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> c(n);
        vector<int> freq(n + 1, 0);

        int common = 0;
        for (int i = 0; i < n; i++) {
            freq[A[i]]++;
            if (freq[A[i]] == 2) {
                common++;
            }

            freq[B[i]]++;
            if (freq[B[i]] == 2) {
                common++;
            }

            c[i] = common;
        }
        return c;
    }
};