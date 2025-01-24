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
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* res = nullptr;
        ListNode* resTemp = nullptr;

        while (head != nullptr) {
            ListNode* temp = head;
            ListNode* prev = head;
            int val = temp->val, count = 0;

            while (temp != nullptr && temp->val == val) {
                count++;
                prev = temp;
                temp = temp->next;
            }

            prev->next = nullptr;

            if (count == 1) {
                if (res == nullptr) {
                    res = resTemp = prev;
                } else {
                    resTemp->next = prev;
                    resTemp = prev;
                }
            }

            head = temp;
        }

        return res;
    }
};