class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int>q;
        q.push(0);
        int n = s.size();
        int maxr = 0;
        vector<bool>vis(n, false);
        vis[0] = true;
        while(!q.empty()){
            queue<int>temp;

            while(!q.empty()){
                int t = q.front();
                q.pop();
                int l = t + minJump;
                int r = min(t + maxJump, n - 1);
                if(l >= n || r <= maxr){
                    continue;
                }
                
                l = max(l, maxr);
                maxr = r;

                for(int i = l; i <= r; i++){
                    if(s[i] == '0' && i == n - 1){
                        return true;
                    }
                    if(s[i] == '0' && !vis[i]){
                        temp.push(i);
                        vis[i] = true;
                    }
                }
            }
            q = temp;
        }
        return false;
    }
};