class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        bool exist = false;
        int n = words.size();
        int minDist = n;
        for(int i = 0; i < n; i++){
            if(words[i] == target){
                exist = true;
                int dist = min(abs(i - startIndex), n - abs(i - startIndex));
                minDist = min(minDist, dist);
            }
        }
        
        return exist? minDist : -1;
    }
};