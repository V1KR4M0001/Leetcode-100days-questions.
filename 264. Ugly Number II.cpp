// An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
// Given an integer n, return the nth ugly number.


// Example 1:
// Input: n = 10
// Output: 12
// Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.

// Example 2:
// Input: n = 1
// Output: 1
// Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
 

// Constraints:
// 1 <= n <= 1690

//  Solution:=>

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans;
        ans.push_back(1);

        int i2 = 0, i3 = 0, i5 = 0;

        for(int i = 1; i < n; i++) {
            int temp = min({ans[i2]*2, ans[i3]*3, ans[i5]*5});
            ans.push_back(temp);

            if(temp == ans[i2] * 2) i2++;
            if(temp == ans[i3] * 3) i3++;
            if(temp == ans[i5] * 5) i5++;
        }

        return ans[n-1];
    }
};
