class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a) {
            pq.push({a, 'a'});
        }
        if (b) {
            pq.push({b, 'b'});
        }
        if (c) {
            pq.push({c, 'c'});
        }

        string res = "";

        while (!pq.empty()) {
            char ch = pq.top().second;
            int freq = pq.top().first;
            pq.pop();

            int n = res.size();

            if (n >= 2 && res[n - 1] == ch && res[n - 2] == ch) {
                if (pq.empty()) {
                    break;
                }
                auto top = pq.top();
                pq.pop();
                res = res + top.second;
                if (top.first - 1 != 0) {
                    pq.push({top.first - 1, top.second});
                }
            } else if (n >= 1 && res[n - 1] == ch) {
                res = res + ch;
                freq--;
            } else {
                if (freq >= 2) {
                    res = res + ch + ch;
                    freq -= 2;
                } else {
                    res = res + ch;
                    freq--;
                }
            }

            if (freq != 0) {
                pq.push({freq, ch});
            }

            cout << res << endl;
        }

        return res;
    }
};