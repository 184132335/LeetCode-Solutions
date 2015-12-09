// Time:  O(n)
// Space: O(k), k is size of the alphabet

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> cnts;
        for (const auto& c : s) {
            ++cnts[c];
        }

        string res;
        unordered_set<char> visited;
        stack<char> stk;
        for (const auto& c : s) {
            if (!visited.count(c) && (stk.empty() || stk.top() != c)) {
                while (!stk.empty() && stk.top() >= c && cnts[stk.top()] > 0) {
                    visited.erase(stk.top());
                    stk.pop();
                }
                stk.emplace(c);
                visited.emplace(c);
            }
            --cnts[c];
        }
        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res; 
    }
};

