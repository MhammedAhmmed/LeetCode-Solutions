class Solution {
    bool isOn(int num, int index){
        return (num >> index) && 1; 
    }
    string intToBin(int num, int n){
        
        string bin = "";
        for(int i = n - 1; i >= 0; i--){
            isOn(num, i) ? bin.push_back('1') : bin.push_back('0');
        }

        return bin;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();

        unordered_set<string>bins;

        for(string num: nums){
            bins.insert(num);
        }

        int maxNum = pow(2, n) - 1;

        for(int i = 0; i <= maxNum; i++){
            string num = intToBin(i, n);
            if(bins.find(num) == bins.end()){
                return num;
            }
        }
        return "";
    }
};