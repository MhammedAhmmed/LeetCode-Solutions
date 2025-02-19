class Solution {
public:
    bool kthSmallest(int n, int& k, int index, string& happy) {
        if (index >= n) {
            return --k == 0;
        }

        char ch = 'a';
        int iter = 3;

        while (iter--) {

            if (happy[index - 1] != ch) {
                happy.push_back(ch);

                if (kthSmallest(n, k, index + 1, happy)) {
                    return true;
                }

                happy.pop_back();
            }

            ch++;
        }

        return false;
    }

    string getHappyString(int n, int k) {

        char ch = 'a';
        int iter = 3;

        string happy = "";
        while (iter--) {
            happy.push_back(ch);

            if (kthSmallest(n, k, 1, happy)) {
                return happy;
            }

            happy.pop_back();

            ch++;
        }

        return happy;
    }
};