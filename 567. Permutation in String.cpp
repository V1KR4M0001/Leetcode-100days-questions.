// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
// In other words, return true if one of s1's permutations is the substring of s2.

 
// Example 1:
// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").

// Example 2:
// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false
 

// Constraints:
// 1 <= s1.length, s2.length <= 104
// s1 and s2 consist of lowercase English letters.

//   Solution:=>
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        if (n > m) return false;

        vector<int> s1_freq(26, 0);
        vector<int> s2_freq(26, 0);

        for (int i = 0; i < n; i++) {
            s1_freq[s1[i] - 'a']++;
        }

        int i = 0; 
        int j = 0; 
        while (j < m) {
            s2_freq[s2[j] - 'a']++;

            if (j - i + 1 > n) {
                s2_freq[s2[i] - 'a']--;
                i++;
            }

            if (s1_freq == s2_freq) {
                return true;
            }

            j++;
        }

        return false;
    }
};
