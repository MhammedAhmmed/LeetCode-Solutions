// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
 
class Solution {
	int getLen(ListNode* head) {
		int len = 0;
		while (head != nullptr) {
			len++;
			head = head->next;
		}

		return len;
	}
public:
	ListNode* deleteMiddle(ListNode* head) {
		int len = getLen(head);

		if (len == 1) {
			return nullptr;
		}

		ListNode* temp = head;
		int mid = len / 2;
		mid--;
		while (mid--) {
			temp = temp->next;
		}

		temp->next = temp->next->next;

		return head;
	}
};