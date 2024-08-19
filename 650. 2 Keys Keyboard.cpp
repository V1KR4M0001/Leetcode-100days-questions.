// There is only one character 'A' on the screen of a notepad. You can perform one of two operations on this notepad for each step:

// Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
// Paste: You can paste the characters which are copied last time.
// Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen.


// Example 1:
// Input: n = 3
// Output: 3
// Explanation: Initially, we have one character 'A'.
// In step 1, we use Copy All operation.
// In step 2, we use Paste operation to get 'AA'.
// In step 3, we use Paste operation to get 'AAA'.

// Example 2:
// Input: n = 1
// Output: 0
 

// Constraints:
// 1 <= n <= 1000

//  Solution:=>

class Solution {
public:
    int minSteps(int n) {
        if(n == 1) return 0;
        if(n == 2) return 2;

        vector<int> t(n+1, 0);

        t[0] = 0;
        t[1] = 0;
        t[2] = 2;

        for(int i = 3; i <= n; i++) {
            int factor = i/2;
            while(factor >= 1) {
                if(i%factor == 0) {
                    int steps = t[factor];
                    int copy = 1;
                    int paste = (i / factor) - 1;

                    t[i] = steps + copy + paste;
                    break;
                } else {
                    factor--;
                }
            }
        }
        return t[n];
    }
};
