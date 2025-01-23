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
    int linkedLen(ListNode* head) {
        int len = 0;

        while (head != nullptr) {
            len++;
            head = head->next;
        }

        return len;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* v1 = head;
        ListNode* v2 = head->next;

        head->next = nullptr;

        while (v2 != nullptr) {
            ListNode* v3 = v2->next;

            v2->next = v1;

            v1 = v2;
            v2 = v3;
        }

        return v1;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) {
            return head;
        }

        int len = linkedLen(head);

        int n = len / k;
        ListNode* res = nullptr;
        ListNode* prev = nullptr;
        for (int i = 0; i < n; i++) {
            ListNode* tempHead = head;
            ListNode* temp = head;

            for (int j = 0; j < k - 1; j++) {
                temp = temp->next;
            }

            head = temp->next;
            temp->next = nullptr;

            ListNode* reversedList = reverseList(tempHead);

            if (res == nullptr) {
                res = reversedList;
            } else {
                prev->next = reversedList;
            }

            prev = tempHead;
        }

        prev->next = head;

        return res;
    }
};