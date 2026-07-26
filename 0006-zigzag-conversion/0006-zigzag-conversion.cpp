class Solution {
public:
    string convert(string s, int numRows) {
        string result="";
        if(numRows == 1 || numRows >= s.size()){
            return s;
        }
        int increment = 2*(numRows-1);
        for (int i = 0; i < numRows; i++){
            for(int j = i; j <s.size();j = j + increment){
                result += s[j];
                if(i > 0 && i < numRows-1 && j+increment - 2*i < s.size()){
                    result += s[j+increment-2*i];
                }
            }
        }
        return result;
    }
};

/*
--------------- Algorithm ----------------

Step 1:
If numRows == 1,
return the original string since no zigzag
pattern can be formed.

Step 2:
Initialize an empty string:
    result = ""

Step 3:
Calculate the zigzag cycle length:

    cycle = 2 × (numRows - 1)

Step 4:
Traverse each row from 0 to numRows-1.

Step 5:
For every row, visit all vertically aligned
characters by jumping 'cycle' positions.

        j = j + cycle

Append each character to result.

Step 6:
For middle rows (neither first nor last),
also append the diagonal character.

        diagonalIndex = j + cycle - 2 × row

Append it only if it lies within the string.

Step 7:
Repeat until all rows are processed.

Step 8:
Return result.

-------------------------------------------
Example:

Input:
s = "PAYPALISHIRING"
numRows = 3

Cycle Length:
2 × (3-1) = 4

Row 0:
0,4,8,12
P A H N

Row 1:
1,3,5,7,9,11,13
A P L S I I G

Row 2:
2,6,10
Y I R

Output:
"PAHNAPLSIIGYIR"

-------------------------------------------
Key Idea:

• Characters repeat after every
  2 × (numRows - 1) positions.

• First and last rows contain only
  vertical characters.

• Middle rows contain both:
    - Vertical characters
    - Diagonal characters

-------------------------------------------
Time Complexity  : O(n)

Space Complexity : O(n)

-------------------------------------------
*/