class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord) {

        int len = searchWord.size(), n = products.size();

        sort(products.begin(), products.end());

        int index = 0;
        vector<vector<string>> res;
        string temp = "";
        for (int i = 0; i < len; i++) {
            temp.push_back(searchWord[i]);

            while (index < n && products[index].substr(0, i + 1) != temp) {
                index++;
            }

            vector<string> suggeste;

            for (int j = 0; j < 3; j++) {
                if (index + j < n) {
                    if (products[index + j].substr(0, i + 1) == temp) {
                        suggeste.push_back(products[index + j]);
                    }
                }
            }

            res.push_back(suggeste);
        }

        return res;
    }
};