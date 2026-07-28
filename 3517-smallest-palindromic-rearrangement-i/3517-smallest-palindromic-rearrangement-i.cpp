class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }

        string res = "";
        char m = ' ';
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                m = char('a' + i);
            }
            for (int j = 0; j < freq[i] / 2; j++) {
                res += char('a' + i);
            }
        }
        res = m == ' ' ? res : res + m;
        for (int i = 0; i < s.size() / 2; i++) {
            res += res[s.size() / 2 - 1 - i];
        }
        return res;
    }
};