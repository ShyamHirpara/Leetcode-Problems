class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> cnd(ratings.size(), 1);
        int n = ratings.size();
        int count = 0;
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                cnd[i] = cnd[i-1] +1;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                cnd[i] = cnd[i] > cnd[i + 1] + 1 ? cnd[i] : cnd[i+1] + 1;
            }
        }
        for (int i = 0; i < n; i++) {
            count += cnd[i];
        }
        return count;
    }
};

/*
---------------------------------------------------------
Algorithm: Candy Distribution
---------------------------------------------------------

Step 1:
Find the number of children (n).

Step 2:
Create an array 'cnd' of size n and initialize every
element to 1, since each child must receive at least
one candy.

Step 3:
Traverse the ratings array from left to right.

    • If the current child's rating is greater than the
      previous child's rating, assign one more candy
      than the previous child.

          cnd[i] = cnd[i-1] + 1

This satisfies the left neighbor condition.

---------------------------------------------------------

Step 4:
Traverse the ratings array from right to left.

    • If the current child's rating is greater than the
      next child's rating, ensure that the current child
      has one more candy than the next child.

          cnd[i] = max(cnd[i], cnd[i+1] + 1)

The max() is used because the left-to-right traversal
may have already assigned a larger number of candies,
which should not be reduced.

This satisfies the right neighbor condition.

---------------------------------------------------------

Step 5:
Traverse the candy array and calculate the total
number of candies distributed.

        count += cnd[i]

---------------------------------------------------------

Step 6:
Return the total number of candies.

---------------------------------------------------------
Example

Input:
ratings = [1, 0, 2]

Initially:
cnd = [1, 1, 1]

Left-to-Right Pass:

ratings[1] < ratings[0]
No change

ratings[2] > ratings[1]
cnd = [1, 1, 2]

Right-to-Left Pass:

ratings[1] < ratings[2]
No change

ratings[0] > ratings[1]
cnd[0] = max(1, 1+1) = 2

Final Candy Distribution:
cnd = [2, 1, 2]

Total Candies:
2 + 1 + 2 = 5

Output:
5

---------------------------------------------------------
Time Complexity  : O(n)
Space Complexity : O(n)
---------------------------------------------------------
*/