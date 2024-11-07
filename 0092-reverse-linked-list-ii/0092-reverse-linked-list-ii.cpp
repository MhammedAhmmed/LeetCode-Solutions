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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int len = right - left + 1;

        ListNode* first = head;

        int l = left;
        while (l != 1) {
            first = first->next;
            l--;
        }

        vector<int> values(len);

        ListNode* temp = first;

        for (int i = 0; i < len; i++) {
            values[i] = temp->val;
            temp = temp->next;
        }

        len = right - left + 1;
        for (int i = len - 1; i >= 0; i--) {
            first->val = values[i];
            first = first->next;
        }

        return head;
    }
};