/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* res = NULL;
        ListNode* tempRes = NULL;
        ListNode* temp = head;

        while (temp != nullptr) {
            if (temp->val < x) {
                ListNode* newNode = new ListNode(temp->val);

                if (res == NULL) {
                    res = newNode;
                    tempRes = newNode;
                } else {
                    tempRes->next = newNode;
                    tempRes = tempRes->next;
                }
            }
            temp = temp->next;
        }

        if (res == NULL) {
            return head;
        }

        temp = head;

        while (temp != nullptr) {
            if (temp->val >= x) {
                ListNode* newNode = new ListNode(temp->val);

                tempRes->next = newNode;
                tempRes = tempRes->next;
            }

            temp = temp->next;
        }

        return res;
    }
};