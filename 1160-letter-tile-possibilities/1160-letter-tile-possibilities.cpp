class Solution {

    int x = 0;

    void allPossibilities(string tiles, string seq, int n, vector<bool>&take){
        if(seq.size() >= n){
            return;
        }

        char prev = '0';
        for(int i = 0; i < n; i++){
            if(!take[i] && tiles[i] != prev){
                prev = tiles[i];
                x++;

                take[i] = true;
                seq.push_back(tiles[i]);

                allPossibilities(tiles, seq, n, take);

                take[i] = false;
                seq.pop_back();
            }
        }
    }
public:
    int numTilePossibilities(string tiles) {
        
        int n = tiles.size();
        string seq = "";
        vector<bool>take(n, false);

        sort(tiles.begin(), tiles.end());
        allPossibilities(tiles, seq, n, take);

        return x;
    }
};