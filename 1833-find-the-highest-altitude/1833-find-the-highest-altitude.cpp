class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();

        for(int i = 1;i < n; i++){
            gain[i] += gain[i-1];
        }

        return max(*max_element(gain.begin(), gain.end()), 0);
    }
};