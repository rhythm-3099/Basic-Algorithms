// rotate the 2D matrix anti-clockwise

/*
Logic: First find the transpose of the matrix, and then, just flip the matrix horizontally
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i,j,k,n=matrix.size();
        
        for(i=0;i<n;i++){
            for(j=i;j<n;j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<n/2;j++){
                int temp = matrix[i][j];
                 matrix[i][j] = matrix[i][n-1-j];
                 matrix[i][n-1-j] = temp;
            }
        }
    }
};