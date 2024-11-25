class Solution {
    int getZerosPos(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0')
                return i;
        }

        return -1;
    }
    bool validPos(int zeroPos, int newPos) {
        if (newPos < 0 || newPos >= 6) {
            return false;
        }

        return (zeroPos / 3 == newPos / 3) || (zeroPos % 3 == newPos % 3);
    }

    string getChild(string s, int zeroPos, int newPos) {
        string child = s;
        child[zeroPos] = s[newPos];
        child[newPos] = '0';

        return child;
    }
    vector<string> getNeighbours(string s) {

        int zeroPos = getZerosPos(s);
        vector<int> pos{1, -1, 3, -3};
        vector<string> child;

        for (int neighbor : pos) {
            if (validPos(zeroPos, zeroPos + neighbor)) {
                child.push_back(getChild(s, zeroPos, zeroPos + neighbor));
            }
        }

        return child;
    }

public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string goal = "123450";

        string state = "";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                state.push_back(char(board[i][j] + '0'));
            }
        }

        queue<string> q;
        unordered_set<string> vis;
        vis.insert(state);

        q.push(state);
        int level = 0;

        while (!q.empty()) {
            queue<string> temp;

            while (!q.empty()) {
                state = q.front();
                q.pop();

                if (state == goal) {
                    return level;
                }

                vector<string> childs = getNeighbours(state);
                for (auto child : childs) {
                    if (vis.find(child) == vis.end()) {
                        temp.push(child);
                        vis.insert(child);
                    }
                }
            }
            level++;
            q = temp;
        }

        return -1;
    }
};