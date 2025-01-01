/*
    Company Tags                : Zoho, Flipkart, Morgan Stanley, Accolite, Amazon, Microsoft, FactSet, Hike, Adobe, Google, Wipro, SAP Labs, CarWale
    Leetcode Link               : https://leetcode.com/problems/two-sum/
*/

/******************************************************************** C++ ********************************************************************/
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        
        for(int i = 0; i<nums.size(); i++) {
            if(mp.count(target-nums[i]))
                return {mp[target-nums[i]], i};
            mp[nums[i]] = i;
        }
        
        return {};
    }
};