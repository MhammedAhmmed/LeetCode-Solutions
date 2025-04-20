class Solution {
public:
    int numRabbits(vector<int>& answers) {

        unordered_map<int,int>freq;

        for(int ans: answers){
            freq[ans]++;
        }

        int res = 0;
        for(auto entry: freq){
            int rab = entry.first + 1;
            int n = entry.second;

            res += (((n + rab - 1) / rab) * rab);
        }
        return res;
    }
};