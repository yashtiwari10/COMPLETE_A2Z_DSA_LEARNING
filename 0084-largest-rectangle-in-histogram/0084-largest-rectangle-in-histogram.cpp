class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int MaxArea = 0;
        int n = heights.size();
        int element;
        for(int i = 0; i<n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                MaxArea = max((heights[element] * (nse - pse - 1)), MaxArea);
            }
            st.push(i);
        }

        while(!st.empty()){
            int nse = n;
            element = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            MaxArea = max(MaxArea, ((nse - pse - 1) * heights[element]));
        }
        return MaxArea;
    }
};