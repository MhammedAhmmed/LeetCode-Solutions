class Solution {
	ListNode* merge(ListNode* l1, ListNode* l2) {
		ListNode* res = nullptr;
		ListNode* temp = nullptr;

		if (l1->val < l2->val) {
			res = l1;
			l1 = l1->next;
			res->next = nullptr;
		}
		else {
			res = l2;
			l2 = l2->next;
			res->next = nullptr;
		}
		temp = res;

		while (l1 != nullptr && l2 != nullptr){
			if (l1->val < l2->val) {
				temp->next = l1;
				l1 = l1->next;
				temp = temp->next;
				temp->next = nullptr;
			}
			else {
				temp->next = l2;
				l2 = l2->next;
				temp = temp->next;
				temp->next = nullptr;
			}
		}

		if (l1 != nullptr) {
			temp->next = l1;
		}
		if (l2 != nullptr) {
			temp->next = l2;
		}

		return res;
	}
public:
	ListNode* sortList(ListNode* head) {
		if (head == nullptr || head->next == nullptr) {
			return head;
		}

		queue<ListNode*>q;
		ListNode* temp;
		while (head != nullptr) {
			temp = head;

			q.push(head);
			head = head->next;
			temp->next = nullptr;
		}

		while (q.size() != 1) {
			ListNode* l1 = q.front();
			q.pop();
			
			ListNode* l2 = q.front();
			q.pop();

			q.push(merge(l1, l2));
		}

		return q.front();
	}
};
