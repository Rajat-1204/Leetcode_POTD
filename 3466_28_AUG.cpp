class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        // Intializing variables
        map<int,vector<int>> mp;
        int row = grid.size();
        int col = grid[0].size();

        // Fill Map using key and corresponding values
        // key = row - col
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                mp[i-j].push_back(grid[i][j]);
            }
        }


        // Sort each diagonal
        // if key < 0(negative), toh mtlb yhh upper triangle ka part hh -> Ascending order 
        // if key >= 0(positive), toh mtlb yhh lower triangle waaala part hh -> Descending order
        for(auto& i : mp){
            if(i.first < 0){
                sort(i.second.begin(),i.second.end());  // increasing order
            }else{
                sort(i.second.rbegin(),i.second.rend()); // Decreasing order
            }
        }

        // Populate or put back values back into the grid or matrix
        // when we are putting values from the front of map, we need to erase that value also.
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                grid[i][j] = mp[i-j].front();
                mp[i-j].erase(mp[i-j].begin());
            }
        }

        // return grid
        return grid;
    }
};
