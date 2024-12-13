
class MyQueue {
public:
	stack<int>pushStack, popStack;
	MyQueue() {

	}

	void push(int x) {
		pushStack.push(x);
	}

	int pop() {
		if (popStack.empty()) {
			while (!pushStack.empty()) {
				popStack.push(pushStack.top());
				pushStack.pop();
			}
		}
		int val = popStack.top();
		popStack.pop();
		return val;
	}

	int peek() {
		if (popStack.empty()) {
			while (!pushStack.empty()) {
				popStack.push(pushStack.top());
				pushStack.pop();
			}
		}
		return popStack.top();
	}

	bool empty() {
		return pushStack.empty() && popStack.empty();
	}
};