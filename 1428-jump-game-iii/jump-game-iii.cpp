class Solution {
public:
    bool canReach(vector<int>& arr, int start) {

        int n = arr.size();
        vector<int>vis(n, false);

        queue<int>q;
        vis[start] = true;
        q.push(start);

        while(!q.empty()){
            queue<int>temp;
            while(!q.empty()){
                int ind = q.front();
                q.pop();
                
                if(arr[ind] == 0){
                    return true;
                }
                
                int pre = ind - arr[ind];
                int post = ind + arr[ind];
                if(pre >= 0 && !vis[pre]){
                    vis[pre] = true;
                    temp.push(pre);
                }
                if(post < n && !vis[post]){
                    vis[post] = true;
                    temp.push(post);
                }
            }
            q = temp;
        }
        return false;
    }
};