/*
    Leetcode Link : https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int r_sum = 0;
        int l_sum = 0;

        for(int i =0; i < n; i++)
        {
            r_sum += nums[i];
        }

        for(int i =0; i < n; i++)
        {
            r_sum -= nums[i];
            if(l_sum == r_sum)
            {
                return i;
            }
            l_sum += nums[i];
        }
        return -1;
    }
};