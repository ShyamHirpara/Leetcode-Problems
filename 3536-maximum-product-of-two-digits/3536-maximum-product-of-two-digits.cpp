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