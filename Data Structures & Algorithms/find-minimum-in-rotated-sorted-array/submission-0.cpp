class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // If mid element is greater than rightmost element,
            // the smallest value must be in the right half
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } 
            // Otherwise, the minimum is in the left half (including mid)
            else {
                right = mid;
            }
        }

        // When left == right, we found the smallest element
        return nums[left];
    }
};
