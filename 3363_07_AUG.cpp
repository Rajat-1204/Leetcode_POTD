class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& grid) {
        // intialize variables
        int n = grid.size();
        int res = 0;

        // first child's diagonal path (0,0) to (n-1,n-1)
        for(int i = 0;i<n;i++){
            res += grid[i][i]; // Add diagonal elements
        }

        // handle the other two children using DP
        for(int pass = 0;pass<2;pass++){
            // Transpose the grid for 3rd child (to reuse same logic)
            if(pass == 1){
                for(int i = 0;i<n;i++){
                    for(int j = i+1;j<n;j++){
                        swap(grid[i][j],grid[j][i]);
                    }
                }
            }

            // intialize DP Arrays
            vector<int> prev(n,-1),curr(n,-1);
            prev[n-1] = grid[0][n-1];

            //Loop from row 1 to row n-2
            for(int row = 1;row<n-1;row++){
                fill(curr.begin(),curr.end(),-1);

                for(int i = 0;i<n;i++){
                // unreachable states -> skip
                    if(prev[i] < 0){
                        continue;
                    }
                // Try moving left
                    if(i>0){
                        curr[i-1] = max(curr[i-1],prev[i] + grid[row][i-1]);
                    }

                // Try moving right
                    if(i < n-1){
                        curr[i+1] = max(curr[i+1],prev[i] + grid[row][i+1]);
                    }

                // Try moving down
                    curr[i] = max(curr[i],prev[i] + grid[row][i]);
                }
            // move to next row
                swap(prev,curr);
            } 

        // add the bottom right corner value after Dp
            res += prev[n-1];
        }
        // return ans
        return res;
    }
};
