class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> maxme(n, -1), maxRight(n, -1);

        int maxR = height[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            maxRight[i] = maxR;
            maxR = max(maxR, height[i]);
        }

        stack<pair<int, int>> st;
        st.push({height[0], 0});

        for (int i = 1; i < n; i++) {
            if (height[i] >= st.top().first) {
                while (!st.empty() && height[i] >= st.top().first) {
                    maxme[st.top().second] = height[i];
                    st.pop();
                }
            }

            st.push({height[i], i});
        }

        int res = 0;

        for (int i = 0; i < n; i++) {
            if (height[i] == 0)
                continue;

            if (maxme[i] != -1) {
                int j;
                for (j = i + 1; height[j] != maxme[i]; j++) {
                    res += height[i] - height[j];
                }
                i = j - 1;
            } else if (maxRight[i] != -1) {
                int j;
                for (j = i + 1; height[j] != maxRight[i]; j++) {
                    res += maxRight[i] - height[j];
                }
                i = j - 1;
            }
        }

        return res;
    }
};