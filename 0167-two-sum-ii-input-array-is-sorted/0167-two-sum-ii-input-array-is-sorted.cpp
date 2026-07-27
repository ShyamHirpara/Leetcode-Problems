class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> indexes(2,0);
        indexes[0] = 0;
        indexes[1] = numbers.size()-1;
        while(indexes[0] < indexes[1]){
            if(numbers[indexes[0]]+numbers[indexes[1]] > target)
                indexes[1]--;
            else if(numbers[indexes[0]]+numbers[indexes[1]] < target)
                indexes[0]++;
            else if(numbers[indexes[0]]+numbers[indexes[1]] == target){
                indexes[0]++;
                indexes[1]++;
                return indexes;
            }
        }
        return indexes;
    }
};