class ProductOfNumbers {
    vector<int>prod;
public:
    ProductOfNumbers() {
        this->prod.push_back(1);
        
    }
    
    void add(int num) {
        if(num == 0){
            this->prod = {1};
            return; 
        }
        int lastProd = this->prod[prod.size() - 1];
        this->prod.push_back(lastProd * num);
    }
    
    int getProduct(int k) {
        if(k >= this->prod.size()){
            return 0;
        }
        int lastProd = this->prod[prod.size() - 1];
        int lastK = this->prod[prod.size() - k - 1];

        return lastProd / lastK;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */