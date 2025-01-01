/*
    Leetcode Link : https://leetcode.com/problems/merge-sorted-array/description/
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m-1;
        int right = 0;
        
        while(left >=0 && right <= n-1)
        {
            if(nums1[left] > nums2[right])
            {
                swap(nums1[left] , nums2[right]);
                left--;
                right++;
            }
            else{
                break;
            }
        }
        int j = 0;
        for(int i = m; i < m+n; i++)
        {
            nums1[i] = nums2[j++];
        }
        sort(nums1.begin(),nums1.end());
        //sort(nums2.begin(),nums2.end());
    }
};