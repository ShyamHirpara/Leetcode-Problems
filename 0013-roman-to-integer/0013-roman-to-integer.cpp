class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> roi;
        roi['I'] = 1;
        roi['V'] = 5;
        roi['X'] = 10;
        roi['L'] = 50;
        roi['C'] = 100;
        roi['D'] = 500;
        roi['M'] = 1000;
        int num = 0; 
        int n = 0;
        while(n < s.size()){
            if(n+1 < s.size() && roi[s[n]] < roi[s[n+1]])
                num -= roi[s[n]];
            else 
                num += roi[s[n]];
            n++;
        }
        return num;
    }
};

/*
---------------------------------------------------------
Algorithm: Roman to Integer
---------------------------------------------------------

Step 1:
Create a hash map to store the integer value
corresponding to each Roman numeral.

    I -> 1
    V -> 5
    X -> 10
    L -> 50
    C -> 100
    D -> 500
    M -> 1000

---------------------------------------------------------

Step 2:
Initialize:

    num = 0      // Stores the final integer value
    n = 0        // Index to traverse the string

---------------------------------------------------------

Step 3:
Traverse the Roman numeral string from left to right.

For each character:

    a) Check if the next character exists.

    b) If the current Roman numeral has a smaller value
       than the next Roman numeral,

            roi[s[n]] < roi[s[n+1]]

       subtract the current value from the result.

            num -= roi[s[n]]

       This handles special cases such as:

            IV = 4
            IX = 9
            XL = 40
            XC = 90
            CD = 400
            CM = 900

---------------------------------------------------------

Step 4:
Otherwise, add the current Roman numeral value
to the result.

        num += roi[s[n]]

---------------------------------------------------------

Step 5:
Move to the next character.

        n++

---------------------------------------------------------

Step 6:
Repeat until the complete string has been
processed.

---------------------------------------------------------

Step 7:
Return the final integer value.

---------------------------------------------------------
Example

Input:
s = "MCMIV"

Traversal:

Character  Next Character   Operation        Result
---------------------------------------------------
M (1000)   C (100)          +1000            1000
C (100)    M (1000)         -100              900
M (1000)   I (1)            +1000           1900
I (1)      V (5)            -1              1899
V (5)      -                +5              1904

Output:
1904

---------------------------------------------------------
Key Observation

Normally, Roman numerals are added together.

Example:
    VIII = 5 + 1 + 1 + 1 = 8

However, if a smaller numeral appears before a
larger numeral, it is subtracted instead of added.

Examples:
    IV = 5 - 1 = 4
    IX = 10 - 1 = 9
    XL = 50 - 10 = 40
    XC = 100 - 10 = 90
    CD = 500 - 100 = 400
    CM = 1000 - 100 = 900

The algorithm checks this condition by comparing
each numeral with the next one while traversing
the string only once.

---------------------------------------------------------
Time Complexity  : O(n)

Space Complexity : O(1)

(The hash map contains only the seven fixed Roman
numerals, so its size is constant.)

---------------------------------------------------------
*/