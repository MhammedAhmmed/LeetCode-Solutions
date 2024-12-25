class RecentCounter {
public:
	vector<int>pings;
	RecentCounter() {

	}

	int ping(int t) {
		pings.push_back(t);

		int l = 0, r = pings.size() - 1;

		int index = r, mid, lessT = t - 3000;
		while (l <= r) {
			mid = (l + r) / 2;

			if (pings[mid] >= lessT) {
				index = mid;
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		return pings.size() - index;
	}
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */