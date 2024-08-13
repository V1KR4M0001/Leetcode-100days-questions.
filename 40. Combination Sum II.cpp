// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target
// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

// Example 1:
// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]

// Example 2:
// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]
 

// Constraints:
// 1 <= candidates.length <= 100
// 1 <= candidates[i] <= 50
// 1 <= target <= 30

//  Solution:=>

class Solution {
public:

    void solve(vector<int>& candidates, int target, vector<int>& current, int idx, vector<vector<int>>& result) {
        if(target < 0) return;
        if(target == 0) {
            result.push_back(current);
            return;
        }
        for(int i=idx; i<candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i-1]) {
                continue;
            }

            current.push_back(candidates[i]);
            solve(candidates, target-candidates[i], current, i+1, result);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;

        sort(begin(candidates), end(candidates));
        solve(candidates, target, current, 0, result);

        return result;
    }
};
