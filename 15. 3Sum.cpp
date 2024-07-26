// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.


// Example 1:
// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.

// Example 2:
// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.

// Example 3:
// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.
 

// Constraints:
// 3 <= nums.length <= 3000
// -105 <= nums[i] <= 105

//  Solution:=>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    int n = nums.size();
    sort(nums.begin(),nums.end());

    for(int i=0;i<n-2;i++){

    if(i==0 || (i>0 && nums[i]!=nums[i-1])){
    int low =i+1;
    int high=n-1;
    int target=-nums[i];

    while(low<high){
        if(nums[low]+nums[high]==target){
            result.push_back({nums[i],nums[low],nums[high]});
        
     while (low < high && nums[low] == nums[low + 1]) low++;
    while (low < high && nums[high] == nums[high - 1]) high--;
                    
                    low++;
                    high--;
                } else if (nums[low] + nums[high] < target) {
                    low++;
                } else {
                    high--;
                }
    }
    }
    }
    return result;
    }
    
};
