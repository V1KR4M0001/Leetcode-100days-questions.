// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).


// Example 1:
// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.

// Example 2:
// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

// Constraints:
// nums1.length == m
// nums2.length == n
// 0 <= m <= 1000
// 0 <= n <= 1000
// 1 <= m + n <= 2000
// -106 <= nums1[i], nums2[i] <= 106

//   Soution:=>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size()-1+nums2.size()-1;
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); i++) {
            ans.push_back(nums2[i]);
        }
        sort(ans.begin(), ans.end());
        if (ans.size() % 2 == 0) {
            return (float)(ans[(ans.size() / 2)] + ans[((ans.size() / 2) - 1)]) / 2;
        } else {
            return ans[ans.size() / 2];
        }
        return (ans.front()+ans.back())/2;
    }
};
