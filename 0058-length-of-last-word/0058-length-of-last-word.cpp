class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        bool isword = false;
        for(int i = s.size() -1; i >= 0;i--){
            isword = s[i] != ' ' ? true : false;
            // if (isword == true)
            //     count++;
            count += isword ? 1 : 0;
            if (!isword && count > 0)
                break;
        }
        return count;
    }
};

/*
--------------- Algorithm ----------------

Step 1:
Initialize:
    count = 0

Step 2:
Traverse the string from the last character to the first.

Step 3:
Ignore all trailing spaces.

Step 4:
Once a non-space character is found,
increment count for every consecutive non-space character.

Step 5:
When a space is encountered after counting has started,
stop the traversal.

Step 6:
Return count as the length of the last word.

-------------------------------------------
Example:
Input : "   fly me   to   the moon  "

Skip trailing spaces
             ↓
"   fly me   to   the moon"

Count:
m → 1
o → 2
o → 3
n → 4

Encounter space → Stop

Output : 4

-------------------------------------------
Time Complexity  : O(n)
Space Complexity : O(1)
-------------------------------------------
*/