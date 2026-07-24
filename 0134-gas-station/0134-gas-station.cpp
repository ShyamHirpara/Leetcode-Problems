class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        for(int i = 0; i < gas.size() ; i++){
            sum += gas[i] -cost[i];
        }    
        if(sum < 0)
            return -1;
        else{
            sum = 0;
            int start = 0;
            for(int i = 0; i < gas.size() ; i++){
                sum += gas[i] -cost[i];
                if(sum < 0){
                    sum = 0;
                    start = i +1;
                }
            }
            return start;
        }
    }
};

/*
---------------------------------------------------------
Algorithm: Gas Station
---------------------------------------------------------

Step 1:
Calculate the total net gas available by summing:

    gas[i] - cost[i]

for every gas station.

Step 2:
If the total net gas is negative, it is impossible to
complete the circular route from any station.
Return -1.

Step 3:
If the total net gas is non-negative, initialize:

    sum = 0
    start = 0

where:
    sum   -> Current fuel remaining in the tank.
    start -> Candidate starting gas station.

Step 4:
Traverse all gas stations from left to right.

    a) Add the net gas gained at the current station:

           sum += gas[i] - cost[i]

    b) If sum becomes negative:

       • The current starting station cannot complete
         the journey up to this point.

       • Any station between the current start and i
         also cannot be a valid starting station.

       • Therefore, set the next station as the new
         candidate starting station.

             start = i + 1

       • Reset the current fuel.

             sum = 0

Step 5:
After completing the traversal, return the value of
'start' as the valid starting gas station.

---------------------------------------------------------
Example

Input:
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]

Net Gas:
[-2, -2, -2, +3, +3]

Traversal:

Station 0:
sum = -2 < 0
start = 1
sum = 0

Station 1:
sum = -2 < 0
start = 2
sum = 0

Station 2:
sum = -2 < 0
start = 3
sum = 0

Station 3:
sum = 3

Station 4:
sum = 6

Output:
3

---------------------------------------------------------
Time Complexity  : O(n)
Space Complexity : O(1)
---------------------------------------------------------
*/