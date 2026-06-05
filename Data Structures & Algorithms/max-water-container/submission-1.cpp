class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxi;
        int n = heights.size();
        int left = 0 ; int right = n-1;
        while(left<right){
        int area = min(heights[left],heights[right])*(right-left);
        maxi=max(maxi,area);
        if(heights[left]<heights[right]){
            left++;
        }else{right--;}
        }
        return maxi;
    }
};
