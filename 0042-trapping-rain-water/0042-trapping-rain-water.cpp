class Solution {
public:
    int trap(vector<int>& height) {

/**
    time complexity O(n) & O(n) memory solution for thi problem 

        int l = 0, r = height.size() - 1, max = 0;
        vector<int> ml(height.size(), 0);
        vector<int> mr(height.size(), 0);
        vector<int> minlr(height.size(), 0);
        for (int i = 0; i < height.size() - 2; i++) {
            // if (height[i]>ml[i])
            //     ml[i+1] = height[i];
            // else
            //     ml[i+1] = ml[i];
            ml[i + 1] = height[i] > ml[i] ? height[i] : ml[i];
        }
        for (int i = height.size() - 1; i > 1; i--) {
            // if (height[i] > mr[i])
            //     mr[i - 1] = [heighti];
            // else
            //     mr[i - 1] = mr[i];
            mr[i - 1] = height[i] > mr[i] ? height[i] : mr[i];
        }
        for (int i = 0; i < height.size(); i++) {
            minlr[i] = ml[i] <= mr[i] ? ml[i] : mr[i];
            max += minlr[i] - height[i] > 0 ? minlr[i] - height[i] : 0;
        }
        return max;

**/

        int L = 0, R = height.size()-1, maxl = height[L] , maxr = height[R], res = 0;
        while (L < R){
            if(maxl<maxr){
                L+=1;
                maxl = maxl > height[L] ? maxl : height[L];
                res += maxl -height[L];
            }
            else{
                R-=1;
                maxr = maxr > height[R] ? maxr :  height[R];
                res += maxr - height[R];
            }
        }
        return res;
    }
};