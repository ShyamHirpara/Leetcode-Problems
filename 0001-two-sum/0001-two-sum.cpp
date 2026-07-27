class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> pos(nums.size());
        vector<int> ans(2,nums.size());
        int count =0;
        for(int& n : nums){
            pos[n] = count++;
        }
        for(int i = 0; i < nums.size(); i++){
            int t = target - nums[i];
            if(pos[t] && pos[t] != i){
                ans[0] = i;
                ans[1] = pos[t];
                return ans;
            }
        }
        return ans;
    }
};