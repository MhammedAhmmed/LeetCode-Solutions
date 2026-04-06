class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int, unordered_set<int>> obst;
        for (vector<int> v : obstacles) {
            obst[v[1]].insert(v[0]);
        }

        int x = 0, y = 0;
        bool N = true, S = false, E = false, W = false;
        int maxDist = 0;

        for (int command : commands) {
            if (command == -1) {
                if (N) {
                    N = false;
                    E = true;
                } else if (S) {
                    S = false;
                    W = true;
                } else if (E) {
                    E = false;
                    S = true;
                } else if (W) {
                    W = false;
                    N = true;
                }
            } else if (command == -2) {
                if (N) {
                    N = false;
                    W = true;
                } else if (S) {
                    S = false;
                    E = true;
                } else if (E) {
                    E = false;
                    N = true;
                } else if (W) {
                    W = false;
                    S = true;
                }
            } else {
                if (N) {
                    for (int i = 0; i < command; i++) {
                        int yn = y + 1;
                        if (!obst[yn].empty() &&
                            obst[yn].find(x) != obst[yn].end()) {
                            break;
                        }
                        y++;
                        maxDist = max(maxDist, (x * x + y * y));
                    }
                } else if (S) {
                    for (int i = 0; i < command; i++) {
                        int yn = y - 1;
                        if (!obst[yn].empty() &&
                            obst[yn].find(x) != obst[yn].end()) {
                            break;
                        }
                        y--;
                        maxDist = max(maxDist, (x * x + y * y));
                    }
                } else if (E) {
                    for (int i = 0; i < command; i++) {
                        int xn = x + 1;
                        if (!obst[y].empty() &&
                            obst[y].find(xn) != obst[y].end()) {
                            break;
                        }
                        x++;
                        maxDist = max(maxDist, (x * x + y * y));
                    }
                } else if (W) {
                    for (int i = 0; i < command; i++) {
                        int xn = x - 1;
                        if (!obst[y].empty() &&
                            obst[y].find(xn) != obst[y].end()) {
                            break;
                        }
                        x--;
                        maxDist = max(maxDist, (x * x + y * y));
                    }
                }
            }
        }

        return maxDist;
    }
};