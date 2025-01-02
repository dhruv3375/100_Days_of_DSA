/*
    Leetcode Link : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/
int removeDuplicates(vector<int>& nums) {
        // Check the number of elements in the vector
        int n = nums.size();
        
        // Edge case: if the array is empty, return 0
        if (n == 0) return 0;
        
        // Initialize the index for unique elements
        int j = 1;
        
        // Iterate over the array starting from the second element
        for(int i = 1; i < n; i++) {
            // If the current element is not the same as the previous one
            if(nums[i] != nums[i-1]) {
                // Place the current element at index j and increment j
                nums[j++] = nums[i];
            }
        }
        
        // Return the number of unique elements
        return j;
    }