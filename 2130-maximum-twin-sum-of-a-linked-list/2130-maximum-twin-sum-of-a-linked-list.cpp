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
int linkedListLen(ListNode* head) {
	int len = 0;
	ListNode* temp = head;
	while (head != nullptr) {
		len++;
		head = head->next;
	}
    return len;
}
public:
    int pairSum(ListNode* head) {
        int len = linkedListLen(head);

        stack<int>nums;
        for (int i = 0; i < len / 2; i++) {
            nums.push(head->val);
            head = head->next;
        }
        int res = 0;
        for (int i = 0; i < len / 2; i++) {
            res = max(res, nums.top() + head->val);
            nums.pop();
            head = head->next;
        }
        return res;
    }
};