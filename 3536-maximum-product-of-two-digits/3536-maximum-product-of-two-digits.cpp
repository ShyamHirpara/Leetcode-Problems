class Solution {
public:
    int maxProduct(int n) {
        int max1 = 0;
        int max2 = 0;
        while (n > 0) {
            max2 = n % 10 >= max1 ? max1 : (n % 10 > max2 ? n % 10 : max2);
            max1 = n % 10 >= max1 ? n % 10 : max1;
            // if (n % 10 >= max1) {
            //     max2 = max1;
            //     max1 = n % 10;
            // }
            // else if (n % 10 > max2) {
            //     max2 = n % 10;
            // }
            n = n / 10;
        }
        return max1 * max2;
    }
};

/*
--------------- Algorithm ----------------

Step 1:
Initialize two variables:
    max1 = 0   // Largest digit
    max2 = 0   // Second largest digit

Step 2:
Extract each digit using:
    digit = n % 10

Step 3:
For every extracted digit:
    • If digit >= max1:
        - Update max2 = max1
        - Update max1 = digit
    • Else if digit > max2:
        - Update max2 = digit

Step 4:
Remove the last digit:
    n = n / 10

Step 5:
Repeat Steps 2–4 until n becomes 0.

Step 6:
Return:
    max1 * max2

-------------------------------------------
Example:

Input:
n = 124

Digits:
4 → max1 = 4, max2 = 0
2 → max1 = 4, max2 = 2
1 → max1 = 4, max2 = 2

Answer:
4 × 2 = 8

-------------------------------------------
Time Complexity  : O(d)
(d = Number of digits)

Space Complexity : O(1)
-------------------------------------------
*/