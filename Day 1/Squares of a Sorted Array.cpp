/*
    Leetcode Link : https://leetcode.com/problems/squares-of-a-sorted-array/description/
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size(), 0); // Result vector to store squared values in sorted order
        int i = 0; // Pointer to the start of the array
        int j = nums.size() - 1; // Pointer to the end of the array
        int n = nums.size();
        int k = n - 1; // Pointer to the position to fill in the result array, starting from the last index

        // Two-pointer approach to compare squares of elements
        while (i <= j) {
            if (nums[i] * nums[i] < nums[j] * nums[j]) {
                result[k--] = nums[j] * nums[j]; // Place the larger square at the current position
                j--; // Move the end pointer left
            } else {
                result[k--] = nums[i] * nums[i]; // Place the larger square at the current position
                i++; // Move the start pointer right
            }
        }

        return result; // Return the sorted squared array
    }
};
