class Solution {
public:
    // DP Array: dp[r][c][turn][curr][dir]
    int dp[501][501][2][2][5];
    int n, m;

    // Recursive function to calculate max length from current cell
    int solve(int r, int c, int turn, int curr, int dir, vector<vector<int>>& grid){
        //  out of bounds check
        if(r == n || c == m || r < 0 || c < 0){
            return 0;
        }

        //  if already computed then return value from DP
        if(dp[r][c][turn][curr][dir] != -1){
            return dp[r][c][turn][curr][dir];
        }
        // check if current cell matches what we expecct(curr)
        if(curr == 1 && grid[r][c] != 2) return 0;
        if(curr == 0 && grid[r][c] != 0) return 0;

        int ans = 0;

        //  Directions
        // 1-> top right 2-> bottom right 3-> bottom left 4-> top left

        if(dir == 1){
            ans = 1 + solve(r-1,c+1,turn,!curr,1,grid);

            if(!turn){
                ans = max(ans, 1 + solve(r+1,c+1,1,!curr,2,grid));
            }
        }

        if(dir == 2){
            ans = 1 + solve(r+1,c+1,turn,!curr,2,grid);

            if(!turn){
                ans = max(ans, 1 + solve(r+1,c-1,1,!curr,3,grid));
            }
        }

        if(dir == 3){
            ans = 1 + solve(r+1,c-1,turn,!curr,3,grid);

            if(!turn){
                ans = max(ans, 1 + solve(r-1,c-1,1,!curr,4,grid));
            }
        }

        if(dir == 4){
            ans = 1 + solve(r-1,c-1,turn,!curr,4,grid);

            if(!turn){
                ans = max(ans, 1 + solve(r-1,c+1,1,!curr,1,grid));
            }
        }
        // store ans in dp and return 
        return dp[r][c][turn][curr][dir] = ans; 
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        // intialize Variables
        int ans = 0;
        n = grid.size();
        m = grid[0].size();

        // initialize dp using memset
        memset(dp,-1,sizeof(dp));


        // try travesing the grid and search for the cell with value 1
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                // if grid[i][j] == 1
                if(grid[i][j] == 1){
                // try all four diagonal directions from "1"
                // starting value after 1 is "2" so curr "1"
                // turn 0 because no turn is used

                // bottom right
                ans = max(ans, 1 + solve(i+1,j+1,0,1,2,grid));
                // top right
                ans = max(ans, 1 + solve(i-1,j+1,0,1,1,grid));
                // bottom left
                ans = max(ans, 1 + solve(i+1,j-1,0,1,3,grid));
                // top left
                ans = max(ans, 1 + solve(i-1,j-1,0,1,4,grid));
                } 
            }
        }
        return ans;
    }
};
