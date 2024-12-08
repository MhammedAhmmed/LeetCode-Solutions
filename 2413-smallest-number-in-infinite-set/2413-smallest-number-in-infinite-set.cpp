class SmallestInfiniteSet {
public:
	unordered_set<int>removedEle;
	priority_queue<int, vector<int>, greater<int>>pq;

	SmallestInfiniteSet() {
		pq.push(1);
	}

	int popSmallest() {
		int smallest = pq.top();
		pq.pop();
		removedEle.insert(smallest);

		if (pq.empty()) {
			pq.push(smallest + 1);
		}

		return smallest;
	}

	void addBack(int num) {
		if (removedEle.find(num) != removedEle.end()) {
			removedEle.erase(num);
			pq.push(num);
		}
	}
};
/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */