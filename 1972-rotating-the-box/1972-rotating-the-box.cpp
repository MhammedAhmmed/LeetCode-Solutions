class Solution {
public:
vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
	int m = box.size(), n = box[0].size();

	int empt = -1;

	for (int i = 0; i < m; i++) {
		empt = -1;
		for (int j = n-1; j >= 0; j--) {
			if (box[i][j] == '.') {
				if (empt == -1) {
					empt = j;
				}
			}
			else if (box[i][j] == '*') {
				empt = -1;
			}
			else {
				if (empt != -1) {
					box[i][j] = '.';
					box[i][empt] = '#';
					empt--;
				}
			}
		}
	}

	vector<vector<char>>res(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			res[i][j] = box[m - j - 1][i];
		}
	}

	return res;
}
};