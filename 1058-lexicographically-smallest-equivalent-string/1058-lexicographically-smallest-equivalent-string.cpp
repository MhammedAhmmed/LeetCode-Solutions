class Solution {
    char findOp(char ch, vector<char>& parents) {

        char parent = ch;
        while (parent != parents[parent - 'a']) {
            parent = parents[parent - 'a'];
        }

        while (ch != parent) {
            char temp = parents[ch - 'a'];
            parents[ch - 'a'] = parent;
            ch = temp;
        }

        return parent;
    }

    void unionOp(char ch1, char ch2, vector<char>& parents) {
        char p1 = findOp(ch1, parents);
        char p2 = findOp(ch2, parents);

        if (p1 < p2) {
            parents[p2 - 'a'] = p1;
        } else {
            parents[p1 - 'a'] = p2;
        }
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {

        vector<char> parents(26);
        for (int i = 0; i < 26; i++) {
            parents[i] = char(i + 'a');
        }

        int n = s1.size();
        for (int i = 0; i < n; i++) {
            unionOp(s1[i], s2[i], parents);
        }

        string res = "";
        for (char ch : baseStr) {
            res.push_back(findOp(ch, parents));
            cout << parents[ch - 'a'];
        }
        return res;
    }
};