// Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


// Example 1:
// Input: rowIndex = 3
// Output: [1,3,3,1]

// Example 2:
// Input: rowIndex = 0
// Output: [1]

// Example 3:
// Input: rowIndex = 1
// Output: [1,1]
 

// Constraints:
// 0 <= rowIndex <= 33

//   Solution:=>

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev;

        for(int i = 0; i < rowIndex+1; i++) {
            vector<int> curr(i+1, 1);

            for(int j = 1; j < i; j++) {
                curr[j] = prev[j] + prev[j-1];
            }
            prev = curr;
        }
        return prev;
    }
};
