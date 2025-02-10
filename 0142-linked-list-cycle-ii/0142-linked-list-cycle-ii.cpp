/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp = head;

        unordered_set<ListNode*>vis;

        while(temp != nullptr){
            if(temp->next != nullptr && vis.find(temp->next) != vis.end()){
                return temp->next;
            }

            vis.insert(temp);
            temp = temp->next;
        }

        return nullptr;
    }
};