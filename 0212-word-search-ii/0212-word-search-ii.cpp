class Node {
public:
    bool isEnd;
    vector<Node*> child;

    Node() {
        isEnd = false;
        child = vector<Node*>(26, nullptr);
    }
};

class Trie {
public:
    Node* root;

    Trie() { root = new Node(); }

    void insert(string str) {
        Node* temp = root;

        for (char ch : str) {
            if (temp->child[ch - 'a'] == nullptr) {
                temp->child[ch - 'a'] = new Node();
            }

            temp = temp->child[ch - 'a'];
        }
        temp->isEnd = true;
    }
};

class Solution {
public:
    vector<string> res;
    vector<int> X{1, -1, 0, 0};
    vector<int> Y{0, 0, 1, -1};

    void dfs(int i, int j, int m, int n, vector<vector<bool>>& vis,
             vector<vector<char>>& board, string word, Node* node) {
        word.push_back(board[i][j]);
        vis[i][j] = 1;

        if (node->isEnd) {
            res.push_back(word);
        }

        for (int k = 0; k < 4; k++) {
            int x = i + X[k];
            int y = j + Y[k];

            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] &&
                node->child[board[x][y] - 'a'] != nullptr) {
                dfs(x, y, m, n, vis, board, word,
                    node->child[board[x][y] - 'a']);
            }
        }

        word.pop_back();
        vis[i][j] = 0;
    }
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        Trie* trie = new Trie();

        for (string word : words) {
            trie->insert(word);
        }

        int m = board.size(), n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (trie->root->child[board[i][j] - 'a'] != nullptr) {
                    string word = "";
                    dfs(i, j, m, n, vis, board, word,
                        trie->root->child[board[i][j] - 'a']);
                }
            }
        }

        unordered_set<string> st;
        for (string word : res) {
            st.insert(word);
        }

        res.clear();

        for (auto str : st) {
            res.push_back(str);
        }

        return res;
    }
};