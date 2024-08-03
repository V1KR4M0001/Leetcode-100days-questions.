// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.


// Example 1:
// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]

// Example 2:
// Input: nums = [1], k = 1
// Output: [1]
 

// Constraints:
// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// k is in the range [1, the number of unique elements in the array].
// It is guaranteed that the answer is unique.
 
// Follow up: 
//Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

//Solution:=>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        vector<int> ans;

        for(int i=0; i<nums.size(); i++) {
            um[nums[i]]++;
        }
        vector<pair<int,int>>v;
        for(auto it : um) {
            v.push_back(make_pair(it.second, it.first));
        }
        sort(v.rbegin(), v.rend());
        for(int i=0; i<v.size() && k!=0; i++) {
            ans.push_back(v[i].second);
            k--;
        }
        return ans;
    }
};
