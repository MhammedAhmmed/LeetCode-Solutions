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
    Node* root;

public:
    Trie() { root = new Node(); }

    void insert(string word) {

        Node* temp = root;

        for (char ch : word) {
            if (temp->child[ch - 'a'] == nullptr) {
                temp->child[ch - 'a'] = new Node();
            }

            temp = temp->child[ch - 'a'];
        }
        temp->isEnd = true;
    }

    bool search(string word) {

        Node* temp = root;

        for (char ch : word) {
            if (temp->child[ch - 'a'] == nullptr) {
                return false;
            }
            temp = temp->child[ch - 'a'];
        }

        return temp->isEnd;
    }

    bool startsWith(string prefix) {

        Node* temp = root;

        for (char ch : prefix) {
            if (temp->child[ch - 'a'] == nullptr) {
                return false;
            }

            temp = temp->child[ch - 'a'];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */