class RandomizedSet {
public:
	unordered_set<int>us;
	RandomizedSet() {
	}

	bool insert(int val) {
		if (us.find(val) == us.end()) {
			us.insert(val);
			return true;
		}

		return false;
	}

	bool remove(int val) {
		if (us.find(val) != us.end()) {
			us.erase(val);
			return true;
		}

		return false;
	}

	int getRandom() {
		int r = us.size();
		int rand = getRandomInRange(0, r - 1);

		auto it = us.begin();

		while (rand--) {
			it++;
		}

		return *it;
	}
	int getRandomInRange(int l, int r) {
		std::random_device rd;
		std::mt19937 gen(rd());       
		std::uniform_int_distribution<> dis(l, r);

		return dis(gen);
	}
};
