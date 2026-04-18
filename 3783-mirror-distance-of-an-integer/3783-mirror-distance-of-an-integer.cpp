class Solution {
public:
    int mirrorDistance(int n) {
        string str = to_string(n);
        reverse(str.begin(), str.end());
        return abs(n - stoi(str));
    }
};