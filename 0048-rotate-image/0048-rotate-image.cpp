class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> temp = matrix;
        for(int i = 0; i < matrix[0].size(); i++){
            for(int j = 0; j < matrix[0].size();j++){
                matrix[i][j] = temp[matrix.size()-1-j][i];
            }
        }
    }
};