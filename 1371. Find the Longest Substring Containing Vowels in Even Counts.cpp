// Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.


// Example 1:
// Input: s = "eleetminicoworoep"
// Output: 13
// Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.

// Example 2:
// Input: s = "leetcodeisgreat"
// Output: 5
// Explanation: The longest substring is "leetc" which contains two e's.

// Example 3:
// Input: s = "bcbcbc"
// Output: 6
// Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero times.
 

// Constraints:
// 1 <= s.length <= 5 x 10^5
// s contains only lowercase English letters.

//   Solution:=>
class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> mp;

        int mask = 0;
        mp[mask] = -1;

        int result = 0;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == 'a') {
                mask = mask ^ (1 << 0);
            } else if(s[i] == 'e') {
                mask = mask ^ (1 << 1);
            }  else if(s[i] == 'i') {
                mask = mask ^ (1 << 2);
            }  else if(s[i] == 'o') {
                mask = mask ^ (1 << 3);
            }  else if(s[i] == 'u') {
                mask = mask ^ (1 << 4);
            }

            if(mp.find(mask) != mp.end()) {
                result = max(result, i-mp[mask]);
            } else {
                mp[mask] = i;
            }
        }
        return result;
    }
};
