class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        //  Initialize variables
        int maxArea = 0;
        int maxDiag = 0;
        int n = dimensions.size();
        // traverse the dimesions vector
        for(int i = 0;i<n;i++){
            int len = dimensions[i][0];
            int wid = dimensions[i][1];

            // calculating squared diagonal
            int currDiag = (len*len) + (wid*wid);

            // comparing diagonals with the previous maximum
            //  and if same found then comparing their areas
            if(currDiag > maxDiag || (currDiag == maxDiag && (len*wid) > maxArea)){
                maxDiag = currDiag;
                maxArea = len * wid;
            }
        }
        //  return area
        return maxArea;
    }
};
