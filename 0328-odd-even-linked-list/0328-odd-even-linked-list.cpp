class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		if (head == nullptr) {
			return head;
		}

		ListNode* odd = head;
		ListNode* even = head->next;

		ListNode* tempO = head;
		ListNode* tempE = head->next;

		while (tempO->next != nullptr && tempE->next != nullptr) {
			tempO->next = tempO->next->next;
			tempO = tempO->next;

			tempE->next = tempE->next->next;
			tempE = tempE->next;
		}
		tempO->next = even;
		return odd;
	}
};
