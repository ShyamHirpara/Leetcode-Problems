class Solution {
public:
    bool isPalindrome(int x) {
        long prev = x, rev = 0;
        if (x < 0)
            return false;
        while (x) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return prev == rev;
    }
};