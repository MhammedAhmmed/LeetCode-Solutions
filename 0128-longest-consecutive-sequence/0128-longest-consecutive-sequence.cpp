class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;

        for(int num: nums){
            st.insert(num);
        }

        int longest = 0;

        for(auto num: st){
            if(st.find(num - 1) == st.end()){
                int len = 0;
                int temp = num;

                while(st.find(temp) != st.end()){
                    len++;
                    temp++;
                }

                longest = max(longest, len);
            }
        }
        
        return longest;
    }
};