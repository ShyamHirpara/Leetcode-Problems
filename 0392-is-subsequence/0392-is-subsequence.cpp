class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = 0;
        if(t.size() == 0 && s.size() == 0)
            return true;
        for(char& c : t){
            // if (c == s[m])
            //     m++;
            m += c == s[m] ? 1 : 0;
            if(m == s.size())
                return true;
        }
        return false;
    }
};