class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> d;
        if(x < 0)
            return false;
        while(x){
            d.push_back(x%10);
            x /= 10;
        }
        for(int i = 0; i < d.size()/2;i++){
            if(d[i] != d[d.size()-1-i])
                return false;
        }

        return true;
    }
};