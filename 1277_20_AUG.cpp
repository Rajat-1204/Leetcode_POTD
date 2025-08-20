class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        // intitialize Variables
        int ans = 0;

        // Get Dimensions of matrix (n and m)
        int n = matrix.size();
        int m = matrix[0].size();

        // Create a DP table with same dimensions
        vector<vector<int>> dp(n,vector<int>(m,0));

        // Intialize the first row and first column of DP with the values using matrix
        // add comtinously to ans also
        for(int i = 0;i<n;i++){
            dp[i][0] = matrix[i][0];
            ans += dp[i][0];
        }
        for(int i = 1;i<m;i++){
            dp[0][i] = matrix[0][i];
            ans += dp[0][i];
        }

        // Traverse the matrix for remaining cells(1->n) & (1->m)
        for(int i = 1;i<n;i++){
            for(int j = 1;j<m;j++){
                // if our mat[i][j] == 1
                if(matrix[i][j] == 1){
                    // update dp with using formula dp[i][j] = 1 + min(left,up,left up diagonal)
                    dp[i][j] = 1 + min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
                }
                // ans += dp[i][j]
                ans += dp[i][j];
            }
        }
        // return ans
        return ans;
    }
};
