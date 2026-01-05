class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int mini = INT_MAX;
        long long sum = 0;
        int negCount = 0;

        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                if(matrix[i][j] < 0){
                    negCount++;
                }

                int absValue = abs(matrix[i][j]);
                mini = min(mini,absValue);
                sum += absValue;
            }
        }
        if(negCount % 2 == 0){
            return sum;
        }        
        return sum - 2*mini;
    }
};

// // all positoves -> full sum

// 1 1
// 1 1

// even no. of negative -> full sum


// 1 -1 1         1 1 1
// 2 -3 -4   ->   2 3 4
// -3 4 5         3 4 5

// odd no. of negative -> maximise using converting all negatives to positives and only left the lowest no. in negative

// 1 1 1          1 1 1
// 2 -3 4   ->    2 3 4
// -3 4 -5        3 4 5


