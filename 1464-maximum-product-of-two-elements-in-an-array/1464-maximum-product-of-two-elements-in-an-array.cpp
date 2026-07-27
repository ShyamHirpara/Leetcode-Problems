class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() <= 2){
            int ans = 1;
            for(int& num : nums){
                ans *= num-1;
            }
            return ans;
        }
        int max1 = INT_MIN; 
        int max2 = INT_MIN;

        int min1 = INT_MAX;
        int min2 = INT_MAX;

        for (int& num : nums){
            max2 = num > max1 ? max1 : num > max2 ? num : max2 ;
            max1 = num > max1 ? num : max1;
            // if (num > max1){
            //     max2 = max1;
            //     max1 = num;
            // }else if (num > max2){
            //     max2 = num;
            // }

            min2 = num < min1 ? min1 : num < min2 ? num : min2;
            min1 = num < min1 ? num : min1;

            // if(num < min1){
            //     min2 = min1;
            //     min1 = num;
            // }else if(num < min2){
            //     min2 = num;
            // }
        }
        max2 -= 1;
        max1 -= 1;
        min1 -= 1;
        min2 -= 1;
        return  max2 * max1 > min2 * min1 ? max2 * max1 : min2 * min1;
    }
};