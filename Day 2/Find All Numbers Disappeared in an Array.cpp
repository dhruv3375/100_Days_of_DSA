/*
    Leetcode Link : https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/solutions/1583736/c-python-all-6-solutions-w-explanations-binary-search-hashset-2x-o-1-space-approach/
*/

// Brute force  t(c) --> o(n^2)

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());

        bool flag = false;

        vector<int>result;

        for(int i =1; i <= n; i++)
        {
            flag = false;
            for(int j =0; j < n; j++)
            {
                if(nums[j] == i)
                {
                    flag = true;
                }
            }
            if(flag == false)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};

// better --> t(c) == o(n) , s(c) = o(n)

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int , int>mp;
        int n = nums.size();
        for(int i =0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        vector<int>result;
        for(int i =1; i <=n; i++)
        {
            if(mp[i] == 0)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};

/*
 Optimal Approach --> t(c) = o(n) , s(c) = o(1)

We want each number  j  (in the range ([1, n])) to be at its "correct position" in the array:
For a number ( j ), the correct position is ( j - 1 ) (since arrays are 0-indexed). So, if  j  is in the array, it should appear at nums[j-1].

For example:
- If nums = [4,3,2,7,8,2,3,1] :
  -  4  should be at nums[3] (index ( 4 - 1 )).
  -  3  should be at nums[2] (index ( 3 - 1 )).
  -  2  should be at nums[1] (index ( 2 - 1 )).
  -  7  should be at nums[6] (index ( 7 - 1 )).


 Steps to Solve

1. Place each number in its correct position:
   - For each number ( c ) in the array, if it's not already in its correct position (i.e., ( nums[c-1] != c )), swap it with the number that is currently in its correct position. 
   - Keep doing this until ( c ) is in the right spot.

2. Identify missing numbers:
   - After ensuring that all numbers are in their correct positions, any index ( i ) where ( nums[i] != i+1 ) corresponds to a missing number ( i+1 ).

 Example Walkthrough

Input: nums = [4,3,2,7,8,2,3,1]

 Step 1: Place numbers in correct positions


---

1. Start with the first number (c = 4):  
   Swap nums[0] (4) with nums[3] (7):  
   nums = [7,3,2,4,8,2,3,1]

2. Now c = 7:  
   Swap nums[0] (7) with nums[6] (3):  
   nums = [3,3,2,4,8,2,7,1]

3. Now c = 3:  
   Swap nums[0]` (3) with nums[2] (2):  
   nums = [2,3,3,4,8,2,7,1]

4. Now c = 2:  
   Swap nums[0] (2) with nums[1] (3):  
   nums = [3,2,3,4,8,2,7,1]

5. Now c = 3:  
   It’s already in the correct position, so move to the next element.

6. For c = 8:  
   Swap nums[4] (8) with nums[7] (1):  
   nums = [1,2,3,4,3,2,7,8]

7. All remaining numbers are in their correct positions.

 Step 2: Identify missing numbers

- Check each index i:
  - At index 4, nums[4] != 5 (it's 3).
  - At index 5, nums[5] != 6 (it's 2).

So, the missing numbers are [5, 6]. 

--- 
 Key Points:
- Swapping ensures numbers go to their correct positions without using extra space.
- Linear time complexity because we process each element at most twice.
- Missing numbers are those whose positions remain incorrect.

*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;

        // Step 1: Place numbers in their correct positions
        for (auto& c : nums) {

            while (nums[c - 1] != c) 
                swap(c, nums[c - 1]);
        }

        // Step 2: Identify missing numbers
        for (int i = 1; i <= nums.size(); i++) {

            if (nums[i - 1] != i) 
                ans.push_back(i);
        }

        return ans;
    }
};



