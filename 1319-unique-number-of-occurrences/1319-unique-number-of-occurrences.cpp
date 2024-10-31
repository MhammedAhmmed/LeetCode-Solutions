class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>freq;

        for(int x : arr){
            freq[x]++;
        }

        map<int,int>mp;

        for(auto entry: freq){
            mp[entry.second]++;

            if(mp[entry.second] > 1)
                return false;
        }
        return true;     
    }

};