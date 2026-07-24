class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        int prefix = 1, postfix = 1;
        for (int i = 0; i < n; i++) {
            result[i] *= prefix;
            result[n - i - 1] *= postfix;
            prefix *= nums[i];
            postfix *= nums[n - i - 1];
        }

        return result;
    }
};


/*
---------------------------------------------------------
Algorithm: Product of Array Except Self
---------------------------------------------------------

Step 1:
Find the size of the input array (n).

Step 2:
Create a result array of size n and initialize every
element with 1.

Step 3:
Initialize two variables:
    prefix  = 1  // Stores product of all elements to the left
    postfix = 1  // Stores product of all elements to the right

Step 4:
Traverse the array from index 0 to n-1.

    a) Store the current prefix product in result[i].

           result[i] = result[i] × prefix

    b) Store the current postfix product in the corresponding
       element from the end.

           result[n-i-1] = result[n-i-1] × postfix

    c) Update the prefix by multiplying it with the current
       element.

           prefix = prefix × nums[i]

    d) Update the postfix by multiplying it with the current
       element from the end.

           postfix = postfix × nums[n-i-1]

Step 5:
After completing the traversal, every index in result
contains:

    (Product of all elements to its left)
            ×
    (Product of all elements to its right)

which is exactly the product of the array except itself.

Step 6:
Return the result array.

---------------------------------------------------------
Example

Input:
nums = [1, 2, 3, 4]

Initial State:
result  = [1, 1, 1, 1]
prefix  = 1
postfix = 1

Iteration 1:
result = [1, 1, 1, 1]
prefix = 1
postfix = 4

Iteration 2:
result = [1, 1, 4, 1]
prefix = 2
postfix = 12

Iteration 3:
result = [1, 12, 8, 1]
prefix = 6
postfix = 24

Iteration 4:
result = [24, 12, 8, 6]

Output:
[24, 12, 8, 6]

---------------------------------------------------------
Time Complexity  : O(n)
Space Complexity : O(1) (excluding the output array)
---------------------------------------------------------
*/