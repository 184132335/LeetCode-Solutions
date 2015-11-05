// Time:  O(C(n, c)), try out all possible substrings with the minimum c deletion.
// Space: O(c), the depth is at most c, and it costs n at each depth

// DFS solution.
class Solution {
public:
    vector<string> removeInvalidParentheses(string s)  {
        // Calculate the minimum left and right parantheses to remove
        int left_removed = 0, right_removed = 0;
        for (const auto& c : s) {
            if (c == '(') {
                ++left_removed;
            } else if (c == ')') {
                if (!left_removed) {
                    ++right_removed;
                } else {
                    --left_removed;
                }
            }
        }
        vector<string> res;
        unordered_set<int> removed;
        removeInvalidParentheses(s, 0, left_removed, right_removed, &removed, &res);
        return res;
    }

    void removeInvalidParentheses(const string& s, int start,
                                  int left_removed, int right_removed,
                                  unordered_set<int> *removed, vector<string> *res) {

        if (left_removed == 0 && right_removed == 0) { 
            string tmp;
            for (int i = 0, j = 0; i < s.length(); ++i) {
                if (!removed->count(i)) {
                    tmp.push_back(s[i]);
                }
            }
            if (isValid(tmp)) {
                res->emplace_back(tmp);
            }
            return;
        }

        for (int i = start; i < s.length(); ++i) {
            if (right_removed == 0 && left_removed > 0 && s[i] == '(') {
                if (i == start || s[i] != s[i - 1]) {  // Skip duplicated.
                    removed->emplace(i);
                    removeInvalidParentheses(s, i + 1, left_removed - 1, right_removed,
                                             removed, res);
                    removed->erase(i);
                }
            } else if (right_removed > 0 && s[i] == ')') {
                if (i == start || s[i] != s[i - 1]) {  // Skip duplicated.
                    removed->emplace(i);
                    removeInvalidParentheses(s, i + 1, left_removed, right_removed - 1,
                                             removed, res);
                    removed->erase(i);
                }
            }

        }
    }

private:
    // Check whether s is valid or not.
    bool isValid(string s) {
        int sum = 0;
        for (const auto &c : s) {
            if (c == '(') {
                ++sum;
            } else if (c == ')') {
                --sum;
            }
            if (sum < 0) {
                return false;
            }
        }
        return sum == 0;
    }
};


// Time:  O(n * C(n, c)), try out all possible substrings with the minimum c deletion.
// Space: O(n * c), the depth is at most c, and it costs n at each depth
// DFS solution.
class Solution2 {
public:
    vector<string> removeInvalidParentheses(string s)  {
        // Calculate the minimum left and right parantheses to remove
        int left_removed = 0, right_removed = 0;
        for (const auto& c : s) {
            if (c == '(') {
                ++left_removed;
            } else if (c == ')') {
                if (!left_removed) {
                    ++right_removed;
                } else {
                    --left_removed;
                }
            }
        }
        vector<string> res;
        removeInvalidParentheses(s, 0, left_removed, right_removed, &res);
        return res;
    }


    void removeInvalidParentheses(const string& s, int start,
                                  int left_removed, int right_removed, vector<string> *res) {

        if (left_removed == 0 && right_removed == 0) {   
            if (isValid(s)) {
                res->emplace_back(s);
            }
            return;
        }

        for (int i = start; i < s.length(); ++i) {
            if (right_removed == 0 && left_removed > 0 && s[i] == '(') {
                if (i == start || s[i] != s[i - 1]) {  // Skip duplicated.
                    string tmp = s;
                    tmp.erase(i, 1);
                    removeInvalidParentheses(tmp, i, left_removed - 1, right_removed, res);
                }
            } else if (right_removed > 0 && s[i] == ')') {
                if (i == start || s[i] != s[i - 1]) {  // Skip duplicated.
                    string tmp = s;
                    tmp.erase(i, 1);
                    removeInvalidParentheses(tmp, i, left_removed, right_removed - 1, res);
                }
            }

        }
    }

private:
    // Check whether s is valid or not.
    bool isValid(string s) {
        int sum = 0;
        for (const auto &c : s) {
            if (c == '(') {
                ++sum;
            } else if (c == ')') {
                --sum;
            }
            if (sum < 0) {
                return false;
            }
        }
        return sum == 0;
    }
};
