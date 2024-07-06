// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

// Example 1:
// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

// Example 2:
// Input: digits = ""
// Output: []

// Example 3:
// Input: digits = "2"
// Output: ["a","b","c"]
 
// Constraints:
// 0 <= digits.length <= 4
// digits[i] is a digit in the range ['2', '9'].

// Solution:
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string arr[10] = {".",   ".",   "abc",  "def", "ghi",
                      "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void solve(string& s, string& output, int i, int n,
               vector<string>& result) {
        if (i == n) {
            result.push_back(output);
            return;
        }
        int digit = s[i] - '0';
        string temp = arr[digit];
        for (int j = 0; j < temp.size(); j++) {
            output.push_back(temp[j]);
            solve(s, output, i + 1, n, result);
            // backtrack
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digit) {
        vector<string> results;
        if (digit.empty())
            return results; // return empty vector if input is empty

        int n = digit.size();
        string output = "";
        solve(digit, output, 0, n, results);
        return results;
    }
};
