class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        // if Matrix is Empty then return blank(empty) vector
        if(matrix.empty() || matrix[0].empty()) return {};

        // initialize Variables
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0;
        int col = 0;

        // create A vector
        vector<int> res(m*n);

        // Traverse krenge poore matrix ko
        for(int i = 0;i<m*n;i++){
            // curr value ko result m dall denge
            res[i] = matrix[row][col];

            // if the indices sum   is even
            if((row + col) % 2 == 0){

                // if last column is there, go down
                if(col == n-1) row++;
                // if first row, then go right
                else if(row == 0) col++;
                // otherwise move up right
                else{
                    row--;
                    col++;
                }
            }

            // else the sum is odd
            else{

                // if last row is there, go right
                if(row == m-1) col++;
                // if first col, then go down
                else if(col == 0) row++;
                // otherwise move down left
                else {
                    row++;
                    col--;
                }
            }

        }
        // return vector
        return res;
    }
};
