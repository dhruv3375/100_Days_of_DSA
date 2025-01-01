/*
    Leetcode Link : https://leetcode.com/problems/majority-element/description/
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int el; // Variable to store the potential majority element
        int count = 0; // Counter for the candidate element

        // Boyer-Moore Voting Algorithm to find the candidate for majority element
        for (int i = 0; i < n; i++) {
            if (count == 0) { // If the count drops to 0, select a new candidate
                el = nums[i];
                count = 1;
            } else if (nums[i] == el) {
                count++; // Increment count if the current element matches the candidate
            } else {
                count--; // Decrement count if the current element does not match
            }
        }

        int final_count = 0; // Variable to validate the candidate
        for (int i = 0; i < n; i++) {
            if (el == nums[i]) {
                final_count++; // Count the occurrences of the candidate in the array
            }
        }

        // Check if the candidate occurs more than n/2 times
        if (final_count > n / 2) {
            return el;
        }

        return -1; // Return -1 if no majority element exists (as per problem requirements)
    }
};
