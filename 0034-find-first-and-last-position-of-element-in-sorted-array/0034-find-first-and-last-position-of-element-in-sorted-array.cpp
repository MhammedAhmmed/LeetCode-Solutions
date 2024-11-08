class Solution {
int getmin(vector<int>& nums, int target) {
	int pos = -1;

	int l = 0, r = nums.size() - 1, mid;

	while (l <= r) {
		mid = (l + r) / 2;

		if (nums[mid] == target) {
			pos = mid;
			r = mid - 1;
			continue;
		}

		if (nums[mid] < target) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	return pos;
}
int getmax(vector<int>& nums, int target) {
	int pos = -1;

	int l = 0, r = nums.size() - 1, mid;

	while (l <= r) {
		mid = (l + r) / 2;

		if (nums[mid] == target) {
			pos = mid;
			l = mid + 1;
			continue;
		}

		if (nums[mid] < target) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	return pos;
}
public:
vector<int> searchRange(vector<int>& nums, int target) {

	vector<int>res(2);
	
	res[0] = getmin(nums, target);
	res[1] = getmax(nums, target);

	cout << res[0] << " " << res[1];
		 
	return res;
}
};