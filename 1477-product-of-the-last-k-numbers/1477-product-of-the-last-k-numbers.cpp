class ProductOfNumbers {
public:
    vector<long long> mul;
    int lastZeroPos = -1;
    int len = 0;
    void add(int num) {
        if (num == 0) {
            lastZeroPos = len;
        }

        if (len == 0 || mul[len - 1] == 0) {
            mul.push_back(num);
        } else {
            mul.push_back(num * mul[len - 1]);
        }

        len++;
    }
    int getProduct(int k) {

        if (lastZeroPos >= len - k) {
            return 0;
        }

        if (len == k || mul[len - k - 1] == 0) {
            return mul[len - 1];
        }

        return mul[len - 1] / mul[len - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */