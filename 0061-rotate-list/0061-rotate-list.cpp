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
    int listLen(ListNode* head) {
        int len = 0;

        while (head != nullptr) {
            len++;
            head = head->next;
        }

        return len;
    }

public:
    ListNode* rotateRight(ListNode* head, int k) {
        int len = listLen(head);
        if (len == 0)
	        return head;
        k = k % len;
        if (k == 0)
            return head;

        ListNode* temp = head;
        int i = len - 1;

        while (i != k) {
            i--;
            temp = temp->next;
        }

        ListNode* temp2 = temp->next;
        temp->next = nullptr;

        temp = temp2;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = head;

        return temp2;
    }
};