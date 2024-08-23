// Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
// Return the sum of the three integers.
// You may assume that each input would have exactly one solution.


// Example 1:
// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

// Example 2:
// Input: nums = [0,0,0], target = 1
// Output: 0
// Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 

// Constraints:
// 3 <= nums.length <= 500
// -1000 <= nums[i] <= 1000
// -104 <= target <= 104

//  Solution:=>

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();

        int closestSum = 100000;

        sort(begin(nums), end(nums));

        for(int k = 0; k <= n-3; k++) {
            int i = k+1;
            int j = n-1;

            while(i < j) {
                int sum = nums[k] + nums[i] + nums[j];

                if(abs(target - sum) < abs(target - closestSum)) closestSum = sum;

                if(sum < target) i++;
                else j--;
            }
        }

        return closestSum;
    }
};
