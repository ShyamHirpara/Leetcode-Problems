class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int max = 0;
        while(l < r){
            if(max < min(height[l],height[r])*(r-l))
                max = min(height[l],height[r])*(r-l);
            if(height[l] >= height[r])
                r--;
            else if(height[l] <= height[r])
                l++;
        }

        return max;
    }
};