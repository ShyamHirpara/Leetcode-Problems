class Solution {
public:
    int trap(vector<int>& height) {

/**
    time complexity O(n) & O(n) memory solution for thi problem 

        int l = 0, r = height.size() - 1, max = 0;
        vector<int> ml(height.size(), 0);
        vector<int> mr(height.size(), 0);
        vector<int> minlr(height.size(), 0);
        for (int i = 0; i < height.size() - 2; i++) {
            // if (height[i]>ml[i])
            //     ml[i+1] = height[i];
            // else
            //     ml[i+1] = ml[i];
            ml[i + 1] = height[i] > ml[i] ? height[i] : ml[i];
        }
        for (int i = height.size() - 1; i > 1; i--) {
            // if (height[i] > mr[i])
            //     mr[i - 1] = [heighti];
            // else
            //     mr[i - 1] = mr[i];
            mr[i - 1] = height[i] > mr[i] ? height[i] : mr[i];
        }
        for (int i = 0; i < height.size(); i++) {
            minlr[i] = ml[i] <= mr[i] ? ml[i] : mr[i];
            max += minlr[i] - height[i] > 0 ? minlr[i] - height[i] : 0;
        }
        return max;

**/

        int L = 0, R = height.size()-1, maxl = height[L] , maxr = height[R], res = 0;
        while (L < R){
            if(maxl<maxr){
                L+=1;
                maxl = maxl > height[L] ? maxl : height[L];
                res += maxl -height[L];
            }
            else{
                R-=1;
                maxr = maxr > height[R] ? maxr :  height[R];
                res += maxr - height[R];
            }
        }
        return res;
    }
};

/*
---------------------------------------------------------
Algorithm: Trapping Rain Water (Two Pointer Approach)
---------------------------------------------------------

Step 1:
Initialize two pointers:

    L = 0                 // Left pointer
    R = n - 1             // Right pointer

Initialize:

    maxl = height[L]      // Maximum height seen from the left
    maxr = height[R]      // Maximum height seen from the right
    res = 0               // Stores total trapped water

---------------------------------------------------------

Step 2:
Repeat until the two pointers meet.

    while (L < R)

---------------------------------------------------------

Step 3:
Compare the maximum heights on both sides.

Case 1:
If maxl < maxr

    • Move the left pointer one step forward.

          L++

    • Update the maximum height seen from the left.

          maxl = max(maxl, height[L])

    • Water trapped at the current position is:

          maxl - height[L]

    • Add this amount to the result.

Reason:
Since maxl is smaller than maxr, the left side
determines the maximum water that can be stored
at the current position.

---------------------------------------------------------

Case 2:
Otherwise (maxr <= maxl)

    • Move the right pointer one step backward.

          R--

    • Update the maximum height seen from the right.

          maxr = max(maxr, height[R])

    • Water trapped at the current position is:

          maxr - height[R]

    • Add this amount to the result.

Reason:
Since maxr is smaller (or equal), the right side
determines the maximum water that can be stored
at the current position.

---------------------------------------------------------

Step 4:
Continue moving the appropriate pointer until
both pointers meet.

---------------------------------------------------------

Step 5:
Return the accumulated trapped water (res).

---------------------------------------------------------
Example

Input:
height = [4, 2, 0, 3, 2, 5]

Initially:

L = 0
R = 5
maxl = 4
maxr = 5
res = 0

Iteration 1:
maxl < maxr

L = 1
Water = 4 - 2 = 2
res = 2

Iteration 2:
L = 2
Water = 4 - 0 = 4
res = 6

Iteration 3:
L = 3
Water = 4 - 3 = 1
res = 7

Iteration 4:
L = 4
Water = 4 - 2 = 2
res = 9

Iteration 5:
L = 5
Pointers meet.

Output:
9

---------------------------------------------------------
Key Observation

Water trapped at any position depends on the
smaller of:

    Maximum height on the left
            and
    Maximum height on the right

Instead of precomputing these maximums for every
index, the two-pointer approach maintains them
dynamically, reducing the extra space requirement
from O(n) to O(1).

---------------------------------------------------------
Time Complexity  : O(n)

Space Complexity : O(1)

---------------------------------------------------------
*/