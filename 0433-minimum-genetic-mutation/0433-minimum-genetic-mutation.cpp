class Solution {
public:
    bool oneChange(string a, string b) {
        int num = 0;
        for (int i = 0; i < 8; i++) {
            if (a[i] != b[i]) {
                num++;
            }
        }
        return num == 1;
    }
    int minMutation(string startGene, string endGene, vector<string>& bank) {

        queue<string> q;
        q.push(startGene);

        int mutation = 0;
        unordered_set<string> vis;
        vis.insert(startGene);

        while (!q.empty()) {
            int len = q.size();

            while (len--) {
                string top = q.front();
                q.pop();

                if (top == endGene) {
                    return mutation;
                }

                for (string s : bank) {
                    if (oneChange(top, s) && vis.find(s) == vis.end()) {
                        q.push(s);
                        vis.insert(s);
                    }
                }
            }

            mutation++;
        }

        return -1;
    }
};