class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int MaxArea = 0;
        int n = heights.size();

        for(int i = 0; i < n; i++) {

            while(!st.empty() && heights[st.top()] > heights[i]) {

                int element = st.top();
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                MaxArea = max(MaxArea,
                    heights[element] * (nse - pse - 1));
            }

            st.push(i);
        }

        while(!st.empty()) {

            int element = st.top();
            st.pop();

            int nse = n;
            int pse = st.empty() ? -1 : st.top();

            MaxArea = max(MaxArea,
                heights[element] * (nse - pse - 1));
        }

        return MaxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> height(m, 0);

        int MaxArea = 0;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }

            MaxArea = max(MaxArea, largestRectangleArea(height));
        }

        return MaxArea;
    }
};