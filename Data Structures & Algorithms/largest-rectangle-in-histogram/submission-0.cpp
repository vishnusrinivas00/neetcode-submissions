class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st; // stores indices
        int maxArea = 0;
        heights.push_back(0); // sentinel to flush out remaining bars
        
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int leftIndex = st.empty() ? -1 : st.top();
                int width = i - leftIndex - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};
