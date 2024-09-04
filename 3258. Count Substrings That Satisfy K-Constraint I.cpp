// You are given a binary string s and an integer k.

// A binary string satisfies the k-constraint if either of the following conditions holds:
// The number of 0's in the string is at most k.
// The number of 1's in the string is at most k.
// Return an integer denoting the number of substrings of s that satisfy the k-constraint.


// Example 1:
// Input: s = "10101", k = 1
// Output: 12
// Explanation:
// Every substring of s except the substrings "1010", "10101", and "0101" satisfies the k-constraint.

// Example 2:
// Input: s = "1010101", k = 2
// Output: 25
// Explanation:
// Every substring of s except the substrings with a length greater than 5 satisfies the k-constraint.

// Example 3:
// Input: s = "11111", k = 1
// Output: 15
// Explanation:
// All substrings of s satisfy the k-constraint.
 

// Constraints:
// 1 <= s.length <= 50 
// 1 <= k <= s.length
// s[i] is either '0' or '1'.

//   Solution:=>

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int cnt0 = 0, cnt1 = 0;
        int ans = 0, l = 0;
        for (int r = 0; r < s.length(); ++r) {
            int x = s[r] - '0';
            cnt0 += x ^ 1;
            cnt1 += x;
            while (cnt0 > k && cnt1 > k) {
                int y = s[l++] - '0';
                cnt0 -= y ^ 1;
                cnt1 -= y;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};
