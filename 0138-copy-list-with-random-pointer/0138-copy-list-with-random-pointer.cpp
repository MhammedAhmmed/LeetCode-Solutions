/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    int getRandomIndex(Node* head, Node* random) {
        if (random == NULL)
            return -1;

        int index = 0;
        while (head != NULL) {
            if (head == random) {
                return index;
            }
            index++;
            head = head->next;
        }

        return 0;
    }
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
        	return NULL;

        map<int, int> mp;

        Node* temp = head;
        int index = 0;

        while (temp != NULL) {
            mp[index++] = getRandomIndex(head, temp->random);
            temp = temp->next;
        }

        int len = index;
        vector<Node*> newList(len);

        temp = head;
        index = 0;

        while (temp != NULL) {
            Node* newNode = new Node(temp->val);
            newList[index++] = newNode;
            temp = temp->next;
        }

        for (int i = 0; i < len; i++) {
            if (mp[i] == -1) {
                newList[i]->random = NULL;
            } else {
                newList[i]->random = newList[mp[i]];
            }

            if (i != len - 1) {
                newList[i]->next = newList[i + 1];
            }
        }

        return newList[0];
    }
};