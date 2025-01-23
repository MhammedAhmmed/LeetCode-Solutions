class Solution {
public:
    string predictPartyVictory(string senate) {
        int Rn = 0, Dn = 0, R = 0, D = 0;

        queue<char> q;
        for (char ch : senate) {
            ch == 'R' ? Rn++ : Dn++;
            q.push(ch);
        }

        while (Rn != 0 && Dn != 0) {
            char ch = q.front();
            q.pop();

            if (ch == 'R') {
                if (D) {
                    D--;
                    Rn--;
                } else {
                    R++;
                    q.push('R');
                }
            } else {
                if (R) {
                    R--;
                    Dn--;
                } else {
                    D++;
                    q.push('D');
                }
            }
        }

        if (Rn) {
            return "Radiant";
        }
        return "Dire";
    }
};