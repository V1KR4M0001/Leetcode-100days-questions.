// Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.


// Example 1:
// Input: s = "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()".

// Example 2:
// Input: s = ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()".

// Example 3:
// Input: s = ""
// Output: 0
 

// Constraints:
// 0 <= s.length <= 3 * 104
// s[i] is '(', or ')'.

//   Solution:=>

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int maxLength = 0;
        
        // Left to right scan
        int open = 0, close = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open++;
            } else {
                close++;
            }

            if (open == close) {
                maxLength = max(maxLength, 2 * close);
            } else if (close > open) {
                open = close = 0;
            }
        }

        // Right to left scan
        open = close = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '(') {
                open++;
            } else {
                close++;
            }

            if (open == close) {
                maxLength = max(maxLength, 2 * open);
            } else if (open > close) {
                open = close = 0;
            }
        }

        return maxLength;
    }
};
