class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int l = 0, r = 0;
        int farthest = 0;
        while (r < nums.size() - 1) {
            farthest = 0;
            for (int i = l; i < r + 1; i++) {
                farthest = (farthest > i + nums[i]) ? farthest : i + nums[i];
            }
            l = r + 1;
            r = farthest;
            jumps++;
        }
        return jumps;
    }
};