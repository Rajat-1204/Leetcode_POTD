class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // Intialize Variables
        vector<vector<int>> result;

        // For Loop -> rows creation
        for(int i = 1;i<=numRows;i++){
            vector<int> temp(i,1);
            //for loop -> updating values according to pascal's triangle
            for(int j = 1;j<i-1;j++){
                temp[j] = result[i-2][j-1] + result[i-2][j];
            }
            result.push_back(temp);
        }
        return result;
    }
};
