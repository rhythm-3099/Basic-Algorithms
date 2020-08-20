// Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0=1, rows=matrix.size(), cols=matrix[0].size();
        int i,j,k;
        for(i=0;i<rows;i++){
            if(matrix[i][0] == 0) 
                col0=0;
            for(j=1;j<cols;j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        for(i=rows-1;i>=0;i--){
            for(j=cols-1;j>=1;j--){
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j]=0;
            }
            if(col0 == 0){
                matrix[i][0] = 0;
            }
        }
    }
};