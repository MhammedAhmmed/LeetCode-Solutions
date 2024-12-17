class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> freq;

        for (char ch : s) {
            freq[ch]++;
        }

        priority_queue<char> pq;
        for (auto entry : freq) {
            pq.push(entry.first);
        }

        string res = "";
        while (!pq.empty()) {
            char largest = pq.top();
            pq.pop();

            int maxAval = min(freq[largest], repeatLimit);
            freq[largest] -= maxAval;

            while (maxAval--) {
                res.push_back(largest);
            }

            if (freq[largest] > 0) {
                if (pq.empty()) {
                    break;
                }

                res.push_back(pq.top());
                freq[pq.top()]--;
                if (freq[pq.top()] == 0) {
                    pq.pop();
                }
                pq.push(largest);
            }
        }

        return res;
    }
};