class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int maxw = 0;
        while(l < r){
            // if(maxw < min(height[l],height[r])*(r-l))
            //     maxw = min(height[l],height[r])*(r-l);
            int w = r - l;
            int h = height[l] < height[r] ? height[l] : height[r];
            maxw = max(maxw,w*h);
            if(height[l] < height[r])
                l++;
            else
                r--;
        }

        return maxw;
    }
};