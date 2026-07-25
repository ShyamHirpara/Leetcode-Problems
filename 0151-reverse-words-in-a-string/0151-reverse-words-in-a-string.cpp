class Solution {
public:
    string reverseWords(string s) {
        int L = 0, R = 0;
        string rev = "";
        for(int i = 0 ; i < s.size(); i++){
            if((i == 0 && s[i] != ' ')||(s[i] != ' ' && s[i-1] == ' ')){
                L = i;
            }
            if((i == s.size()-1 && s[i] != ' ') ||(s[i] != ' ' && s[i+1] == ' ')){
                R = i;
                rev = rev.size() != 0 ? rev+' ' : rev; 
                for(int j = R; j > L-1; j--)
                    rev += s[j];
                L = R;
            }
        }
        for(int i = 0 ; i < rev.size()/2;i++){
            swap(rev[i],rev[rev.size()-1-i]);
        }
        return rev;
    }
};

/*
--------------- Algorithm ----------------

Step 1:
Initialize:
    L = 0, R = 0
    rev = ""

Step 2:
Traverse the string from left to right.

Step 3:
Identify the start (L) and end (R) of each word.
    • L → First non-space character of a word.
    • R → Last non-space character of a word.

Step 4:
For every word found:
    • Add a space to rev (except before the first word).
    • Append the current word in reverse order
      (from R to L) to rev.

Step 5:
After processing all words, reverse the entire
string rev.

Step 6:
Return rev.

-------------------------------------------
Example:

Input:
"the sky is blue"

After Step 4:
"eht yks si eulb"

After reversing entire string:
"blue is sky the"

-------------------------------------------
Time Complexity  : O(n)
Space Complexity : O(n)
-------------------------------------------
*/