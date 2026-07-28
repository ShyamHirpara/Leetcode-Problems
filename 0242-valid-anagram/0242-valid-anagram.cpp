class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sc(26,0);
        vector<int> st(26,0);
        for(char& c : s){
            sc[c-'a']++;
        }
        for(char& c : t){
            st[c-'a']++;
        }
        int n = 0;
        while(n < 26){
            if(sc[n] != st[n])
                return false;
            else 
                n++;
        }
        return true;
    }
};