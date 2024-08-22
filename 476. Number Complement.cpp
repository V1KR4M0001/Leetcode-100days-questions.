Skip to content
Navigation Menu

Code
Issues
Pull requests
Actions
Projects
Wiki
Security
Creating a new file in Leetcode-100days-questions.
BreadcrumbsLeetcode-100days-questions.
/
476 Number Complement.cpp
in
main

Edit

Preview
Indent mode

Spaces
Indent size

2
Line wrap mode

No wrap
Editing 476 Number Complement.cpp file contents
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
// The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.
// For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
// Given an integer num, return its complement.


// Example 1:
// Input: num = 5
// Output: 2
// Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.

// Example 2:
// Input: num = 1
// Output: 0
// Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 

// Constraints:
// 1 <= num < 231
 

// Note: This question is the same as 1009: https://leetcode.com/problems/complement-of-base-10-integer/

//  Solution:=>

class Solution {
public:
    int findComplement(int num) {
        int i = 0;
        int compliment = 0;
        while(num) {
            if(!(num&1)) {
                compliment |= (1 << i);
            }

            num >>= 1;
            i++;
        }
        return compliment;
    }
};
Use Control + Shift + m to toggle the tab key moving focus. Alternatively, use esc then tab to move to the next interactive element on the page.
New File at / · V1KR4M0001/Leetcode-100days-questions.
