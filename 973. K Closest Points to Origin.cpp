// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).
// The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).
// You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).


// Example 1:
// Input: points = [[1,3],[-2,2]], k = 1
// Output: [[-2,2]]
// Explanation:
// The distance between (1, 3) and the origin is sqrt(10).
// The distance between (-2, 2) and the origin is sqrt(8).
// Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
// We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].

// Example 2:
// Input: points = [[3,3],[5,-1],[-2,4]], k = 2
// Output: [[3,3],[-2,4]]
// Explanation: The answer [[-2,4],[3,3]] would also be accepted.
 

// Constraints:
// 1 <= k <= points.length <= 104
// -104 <= xi, yi <= 104

//  Solution:=>

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        priority_queue<pair<int,int>> pq;
        for(int i=0; i<n; i++) {
            int xi=points[i][0];
            int yi=points[i][1];
            int d=(xi*xi)+(yi*yi);
            pq.push({d,i});
            if(pq.size()>k) {
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()) {
            pair<int, int> top=pq.top();
            pq.pop();
            int ind=top.second;

            ans.push_back(points[ind]);
        }
        return ans;
    }
};
