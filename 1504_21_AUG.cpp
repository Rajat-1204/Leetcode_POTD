class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        //  Intialize variable
        int r = mat.size();
        int c = mat[0].size();
        int ans = 0;
        vector<int> h(c);

        // traversal hrrr row ka
        for(int i = 0;i<r;i++){

            // build hieghts of histogram
            for(int j = 0;j<c;j++){
                h[j] = mat[i][j] == 1 ? h[j] + 1 : 0;
            }

            // submatrices ending at j (iske liye ek vector bnayenge)
            vector<int> sum(c);
            stack<int> st;

            // Process the row's of histogram
            for(int j = 0;j<c;j++){
                // Maintain increasing stack
                while(!st.empty() && h[st.top()] >= h[j]){
                    st.pop();
                }

                // if stack is not empty then calculate the value using formula
                // sum[j] = sum[p] + h[j]*(j-p)
                // j - current index; p -> stack k top pe jo available hh 
                if(!st.empty()){
                    int p = st.top();
                    sum[j] = sum[p] + h[j]*(j-p);
                }
                // if stack is empty
                // sum[j] = h[j]*(j+1);
                else{
                    sum[j] = h[j] * (j+1);
                }
                st.push(j);
                // ans m add krdenge sum[j]
                ans += sum[j];
            }
        }
        // return ans        
        return ans;
    }
};
