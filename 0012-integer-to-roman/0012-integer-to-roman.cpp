class Solution {
public:
    string intToRoman(int num) {

        vector<int> value = {1000,900,500,400,100,90,50,40,10,9,5,4,1};

        vector<string> symbol = {
            "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"
        };

        string res;

        for(int i = 0; i < value.size(); i++) {
            while(num >= value[i]) {
                res += symbol[i];
                num -= value[i];
            }
        }

        return res;
    }
};

/*
--------------- Algorithm ----------------

Step 1:
Create two arrays:
    value[]  = {1000,900,500,400,100,90,50,40,10,9,5,4,1}
    symbol[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"}

Step 2:
Initialize an empty string:
    result = ""

Step 3:
Traverse the value array from largest to smallest.

Step 4:
While num >= value[i]:
    • Append symbol[i] to result.
    • Subtract value[i] from num.

Step 5:
Repeat until num becomes 0.

Step 6:
Return result.

-------------------------------------------
Time Complexity  : O(1)
Space Complexity : O(1)
-------------------------------------------
*/