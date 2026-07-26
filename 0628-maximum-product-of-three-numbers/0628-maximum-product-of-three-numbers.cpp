class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size() <= 3){
            int ans = 1;
            for(int& num : nums){
                ans *= num;
            }
            return ans;
        }
        int max1 = INT_MIN; 
        int max2 = INT_MIN;
        int max3 = INT_MIN;

        int min1 = INT_MAX;
        int min2 = INT_MAX;

        for (int& num : nums){
            max3 = num > max1 ? max2 : num > max2 ? max2 : num > max3 ? num : max3 ;
            max2 = num > max1 ? max1 : num > max2 ? num : max2 ;
            max1 = num > max1 ? num : max1;
            // if (num > max1){
            //     max3 = max2;
            //     max2 = max1;
            //     max1 = num;
            // }else if (num > max2){
            //     max3 = max2;
            //     max2 = num;
            // }else if (num > max3){
            //     max3 = num;
            // }

            min2 = num < min1 ? min1 : num < min2 ? num : min2;
            min1 = num < min1 ? num : min1;

            // if(num < min1){
            //     min2 = min1;
            //     min1 = num;
            // }else if(num < min2){
            //     min2 = num;
            // }
        }
        return max1 * max2 * max3 > max1 * min1 * min2 ? max1 * max2 * max3 : max1 * min1 * min2 ;
    }
};

/*
--------------- Algorithm ----------------

Step 1:
If the array contains only 3 elements,
multiply all three numbers and return the result.

Step 2:
Initialize:
    max1, max2, max3 = INT_MIN
        // Three largest numbers

    min1, min2 = INT_MAX
        // Two smallest (most negative) numbers

Step 3:
Traverse the array once.

For each element:

    • Update the three largest numbers.
      Shift existing values whenever a larger
      element is found.

    • Update the two smallest numbers.
      Shift existing values whenever a smaller
      element is found.

Step 4:
After traversal, calculate two possible products:

    Product1 = max1 × max2 × max3
        (Three largest numbers)

    Product2 = max1 × min1 × min2
        (Largest positive and two smallest negatives)

Step 5:
Return the larger of Product1 and Product2.

-------------------------------------------
Example:

Input:
nums = [-10, -10, 5, 2]

Largest Numbers:
max1 = 5
max2 = 2
max3 = -10

Smallest Numbers:
min1 = -10
min2 = -10

Product1 = 5 × 2 × (-10) = -100
Product2 = 5 × (-10) × (-10) = 500

Answer = 500

-------------------------------------------
Time Complexity  : O(n)
Space Complexity : O(1)
-------------------------------------------
*/