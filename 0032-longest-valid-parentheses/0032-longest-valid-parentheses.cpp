class Solution {
public:
    int longestValidParentheses(string s) {

        int n = s.size();

        if (n <= 1) {
            return 0;
        }

        vector<int> openIndex;
        vector<int> maxLen(n, 0);
        vector<bool> validEnd(n, false);

        if (s[0] == '(') {
            openIndex.push_back(0);
        }

        for (int i = 1; i < n; i++) {
            if (s[i] == '(') {
                openIndex.push_back(i);
            }

            if (s[i] == ')') {
                if (openIndex.empty()) {
                    maxLen[i] = maxLen[i - 1];
                } else {
                    int openPos = openIndex[openIndex.size() - 1];
                    openIndex.pop_back();

                    maxLen[i] = i - openPos + 1;
                    validEnd[i] = true;

                    if (openPos != 0 && validEnd[openPos - 1]) {
                        maxLen[i] += maxLen[openPos - 1];
                    }
                }
            }
        }

        return *max_element(maxLen.begin(), maxLen.end());
    }
};