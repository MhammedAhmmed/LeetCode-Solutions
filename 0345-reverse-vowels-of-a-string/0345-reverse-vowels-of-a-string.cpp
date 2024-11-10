class Solution {
    bool isVowel(char ch, vector<char>&vowels){
        for(char vowel : vowels){
            if(ch == vowel){
                return true;
            }
        }
        return false;
    }
public:
    string reverseVowels(string s) {
        int n = s.size();
        vector<char>vowels = {'a', 'e', 'i', 'o','u', 'A', 'E', 'I', 'O','U'};
        string temp = "";

        for(int i = 0; i < n; i++){
            if(isVowel(s[i], vowels)){
                temp.push_back(s[i]);
            }
        }

        int index = 0;
        for(int i = n-1; i >= 0; i--){
            if(isVowel(s[i], vowels)){
                s[i] = temp[index++];
            }
        } 

        return s;     
    }
};