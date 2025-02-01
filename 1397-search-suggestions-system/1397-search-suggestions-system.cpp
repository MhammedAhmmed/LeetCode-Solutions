
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
    void insertWords(string word, Node* node, vector<string>& suggest) {
        if (node == nullptr || suggest.size() == 3) {
            return;
        }

        if (node->isEnd) {
            suggest.push_back(word);
        }

        for (int i = 0; i < 26; i++) {
            if (node->child[i] != nullptr) {
                word.push_back((char)(i + 'a'));
                insertWords(word, node->child[i], suggest);
                word.pop_back();
            }
        }
    }
    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord) {

        Trie* trie = new Trie();

        for (string product : products) {
            trie->insert(product);
        }

        string word = "";
        Node* temp = trie->root;

        vector<vector<string>> res;
        for (char ch : searchWord) {
            vector<string> suggest;

            if (temp->child[ch - 'a'] != nullptr) {
                temp = temp->child[ch - 'a'];

                word.push_back(ch);
                insertWords(word, temp, suggest);

                res.push_back(suggest);
            } else {
                break;
            }
        }

        int additional = searchWord.size() - word.size();

        while (additional--) {
            res.push_back({});
        }

        return res;
    }
};