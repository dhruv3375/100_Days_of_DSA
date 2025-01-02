/*
    Leetcode Link : https://leetcode.com/problems/intersection-of-two-arrays/description/
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int i = 0;
        int j = 0;

        sort(nums1.begin() , nums1.end());
        sort(nums2.begin() , nums2.end());

        vector<int>result;

        while(i < n1 && j < n2)
        {
            if(nums1[i] < nums2[j])
            {
                i++;
            }
            else if(nums1[i] > nums2[j])
            {
                j++;
            }
            else{
                if(result.empty() || result.back() != nums1[i]){

                    result.push_back(nums1[i]);
                }
                i++;
                j++;
            }
        }
        return result;

        
    }
};