class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size() - 1;
        int most = 0;

        while(left < right){
            int area = min(heights[left], heights[right]) * (right - left);
            most = max(most, area);

            if(heights[left] < heights[right])
                left++;
            else
                right--;
        }

        return most;
    }
};
