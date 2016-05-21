// If the given array is not sorted and the memory is unlimited:
//   - Time:  O(m + n)
//   - Space: O(min(m, n))
// elif the given array is already sorted:
//   if the memory is unlimited, and (m << n or m >> n)
//     - Time:  O(min(m, n) * log(max(m, n)))
//     - Space: O(min(m, n))
//   else:
//     - Time:  O(m + n)
//     - Soace: O(1)
// elif the memory is limited:
//     - Time:  O(max(m, n) * log(max(m, n)))
//     - Space: O(max(m, n))

// If the given array is not sorted and the memory is unlimited.
// Time:  O(m + n)
// Space: O(min(m, n))
// Hash solution.
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersect(nums2, nums1);
        }

        unordered_map<int, int> lookup;
        for (const auto& i : nums1) {
            ++lookup[i];
        }

        vector<int> result;
        for (const auto& i : nums2) {
            if (lookup[i] > 0) {
                result.emplace_back(i);
                --lookup[i];
            }
        }

        return result;
    }
};


// If the given array is already sorted, and the memory is unlimited, and (m << n or m >> n).
// Time:  O(min(m, n) * log(max(m, n)))
// Space: O(min(m, n))
// Binary search solution.
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersect(nums2, nums1);
        }

        // Make sure it is sorted, doesn't count in time.
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        unordered_map<int, int> cnts;
        for (const auto& i : nums1) {
            const auto left_it = lower_bound(nums2.cbegin(), nums2.cend(), i);
            const auto right_it = upper_bound(nums2.cbegin(), nums2.cend(), i);
            const auto cnt = right_it - left_it;
            if (cnts[i] < cnt) {
                ++cnts[i];
            }
        }

        vector<int> result;
        for (const auto& kvp : cnts) {
            vector<int> tmp(kvp.second, kvp.first);
            move(tmp.begin(), tmp.end(), back_inserter(result));
        }
        
        return result;
    }
};


// If the given array is already sorted, and the memory is limited or m ~ n.
// Time:  O(m + n)
// Soace: O(1)
// Two pointers solution.
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        // Make sure it is sorted, doesn't count in time.
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        auto it1 = nums1.cbegin(), it2 = nums2.cbegin();
        while (it1 != nums1.cend() && it2 != nums2.cend()) {
            if (*it1 < *it2) {
                ++it1;
            } else if (*it1 > *it2) {
                ++it2;
            } else {
                result.emplace_back(*it1);
                ++it1, ++it2;
            }
        }
        return result;
    }
};


// If the given array is not sorted, and the memory is limited.
// Time:  O(max(m, n) * log(max(m, n)))
// Space: O(1)
// Two pointer solution.
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        // O(max(m, n) * log(max(m, n)))
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        auto it1 = nums1.cbegin(), it2 = nums2.cbegin();
        while (it1 != nums1.cend() && it2 != nums2.cend()) {
            if (*it1 < *it2) {
                ++it1;
            } else if (*it1 > *it2) {
                ++it2;
            } else {
                result.emplace_back(*it1);
                ++it1, ++it2;
            }
        }
        return result;
    }
};
