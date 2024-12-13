class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();

        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (st.empty() || st.top() < 0 || asteroids[i] > 0) {
                st.push(asteroids[i]);
            } else {
                while (!st.empty() && st.top() > 0 &&
                       abs(asteroids[i]) > st.top()) {
                    st.pop();
                }

                if (!st.empty() && abs(asteroids[i]) == st.top()) {
                    st.pop();
                } else if (st.empty() || st.top() < 0) {
                    st.push(asteroids[i]);
                }
            }
        }

        int resLen = st.size();
        vector<int> res(resLen);

        for (int i = resLen - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};