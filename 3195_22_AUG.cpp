class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        // Intialize variables
        int row = grid.size();
        int col = grid[0].size();

        // intialize boundaries
        int top = row;
        int bottom = -1;
        int left = col;
        int right = -1;

        // Traverse krenge poore grid ko
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                // jha prr bhi 1 aaya wha values ko update krenge
                if(grid[i][j] == 1){
                    top = min(top,i);               // Top -> min(Top,row_index)
                    bottom = max(bottom,i);         // bottom -> max(bottom,row_index)
                    left = min(left,j);             // left -> min(left,col_index)
                    right = max(right,j);           // right -> max(right,col_index)
                }
            }
        }
                    
        // calculate Area => (bottom - top + 1) * (right - left + 1)
        int area = (bottom - top + 1) * (right - left + 1);

        return area;
    }
};
