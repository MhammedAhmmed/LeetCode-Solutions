struct Node {
	int val;
	int key;
	Node* next;
	Node* prev;

	Node(int x, int y): val(x), key(y), next(nullptr), prev(nullptr){}
};
class LRUCache {
public:
	unordered_map<int, Node*>mp;
	Node* first;
	Node* last;

	int size = 0;
	int capacity;
	LRUCache(int capacity) {
		first = last = nullptr;
		this->capacity = capacity;
	}

	void putLast(Node* temp) {
		if (size <= 1) {
			return;
		}

		if (temp->key == first->key) {
			first = first->next;

			first->prev = nullptr;
			temp->next = nullptr;
		}
		else if (temp->key == last->key) {
			last = last->prev;

			last->next = nullptr;
			temp->prev = nullptr;
		}
		else if (temp->next != nullptr && temp->prev != nullptr) {
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;

			temp->next = nullptr;
			temp->prev = nullptr;
		}

		last->next = temp;
		temp->prev = last;
		last = temp;
	}

	int get(int key) {
		if (mp.find(key) == mp.end()) {
			return -1;
		}

		Node* temp = mp[key];
		putLast(temp);

		return temp->val;
	}

	void put(int key, int value) {
		if (size == 0) {
			Node* node = new Node(value, key);
			mp[key] = node;

			first = last = node;
			size++;
		}
		else {
			if (mp.find(key) != mp.end()) {
				Node* node = mp[key];

				node->val = value;
				putLast(node);
			}
			else {
				Node* node = new Node(value, key);
				mp[key] = node;
				last->next = node;
				node->prev = last;
				last = node;

				if (size < capacity) {
					size++;
				}
				else {
					mp.erase(first->key);

					Node* temp = first;
					first = first->next;
					first->prev = nullptr;
					temp->next = nullptr;
				}
			}
		}
	}
};