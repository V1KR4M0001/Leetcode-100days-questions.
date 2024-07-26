// Given an m x n matrix, return all elements of the matrix in spiral order.


// Example 1:
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]

// Example 2:
// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

// Constraints:
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100

//  Solution:=>

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
       vector<int> ans;
       int n=arr.size();
       int m=arr[0].size();
       int left=0, right=m-1;
       int top=0, bottom=n-1;

       while((left<=right) && (top<=bottom)){
        for(int i=left; i<=right; i++){
            ans.push_back(arr[top][i]);
        }
        top++;
        if(top>bottom){
            break;
        }
        for(int j=top; j<=bottom; j++){
            ans.push_back(arr[j][right]);
        }
        right--;
        if(left>right){
            break;
        }
        for(int i=right; i>=left; i--){
            ans.push_back(arr[bottom][i]);
        }
        if(top>bottom){
            break;
        }
        bottom--;
        for(int j=bottom; j>=top; j--){
            ans.push_back(arr[j][left]);
        }
        left++;
       }
       return ans; 
    }
};
