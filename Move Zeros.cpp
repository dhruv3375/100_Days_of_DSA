/*
    Leetcode Link : https://leetcode.com/problems/move-zeroes/description/
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = 0; // Pointer to place non-zero elements
        int cnt = 0; // Counter to track the number of zeros

        // Move all non-zero elements to the front of the array
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            } else {
                cnt++; // Increment zero count
            }
        }

        // Fill the remaining positions with zeros
        while (cnt--) {
            nums[j++] = 0;
        }
    }
};
