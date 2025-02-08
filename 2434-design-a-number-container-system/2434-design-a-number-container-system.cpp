class NumberContainers {
    unordered_map<int,int>indNum;
    unordered_map<int,set<int>>indixes;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(indNum[index] != 0){
            indixes[indNum[index]].erase(index);
        }

        indNum[index] = number;
        indixes[number].insert(index);        
    }
    
    int find(int number) {
        if(indixes[number].empty()){
            return -1;
        }

        return *indixes[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */