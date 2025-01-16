// class Node {
// public:
// 	int val;
// 	Node* left;
// 	Node* right;
// 	Node* next;

// 	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

// 	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

// 	Node(int _val, Node* _left, Node* _right, Node* _next)
// 		: val(_val), left(_left), right(_right), next(_next) {}
// };


class Solution {
public:
	Node* connect(Node* root) {
		if (root == nullptr) {
			return nullptr;
		}

		queue<Node*> q;

		q.push(root);

		while (!q.empty()) {

			int n = q.size();
			while (n--) {
				Node* top = q.front();
				q.pop();

				if (top->left != nullptr) {
					q.push(top->left);
				}
				if (top->right != nullptr) {
					q.push(top->right);
				}

				if (n) {
					top->next = q.front();
				}
			}
		}
		return root;
	}
};