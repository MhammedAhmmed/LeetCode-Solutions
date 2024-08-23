class Solution {
pair<int, int> lenWage(vector<int>& num, int index, bool greater, int n) {
	int res = 1;
	while (index < n - 1) {
		if (greater) {
			if (num[index] > num[index + 1]) {
				index++;
				greater = false;
				res++;
			}
			else {
				break;
			}
		}
		else {
			if (num[index] < num[index + 1]) {
				index++;
				greater = true;
				res++;
			}
			else {
				break;
			}
		}
	}
	return { index, res };
}
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int res = 1, n = arr.size();

        for (int i = 0; i < n - 1; i++) {
            if (arr[i] == arr[i + 1])
                continue;
            pair<int, int>wage;
            if (arr[i] > arr[i + 1]) {
                wage = lenWage(arr, i, true, n);
            }
            else {
                wage = lenWage(arr, i, false, n);
            }

            res = max(res, wage.second);
            i = wage.first - 1;
        }
        return res;
    }
};