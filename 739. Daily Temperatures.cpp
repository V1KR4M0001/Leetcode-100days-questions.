// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

  
// Example 1:
// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]

// Example 2:
// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]

// Example 3:
// Input: temperatures = [30,60,90]
// Output: [1,1,0]


// Constraints:
// 1 <= temperatures.length <= 105
// 30 <= temperatures[i] <= 100

//    Solution:=>

class Solution {
public:
    vector<int> NGR(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> idx_NGR(n);
        stack<int> st;
        idx_NGR[n-1]=-1;
        st.push(n-1);

        for(int i=n-2; i>=0; i--){
            while(!st.empty() && temperatures[st.top()]<=temperatures[i]){
                st.pop();
            }
            idx_NGR[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return idx_NGR;
    }

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> idx_NGR = NGR(temperatures);
        vector<int> res(n);
        for(int i=0; i<n; i++){
            if(idx_NGR[i] == -1){
                res[i] = 0;
            }else{
                res[i]=idx_NGR[i]-i;
            }
        }
        return res;
    }
};
