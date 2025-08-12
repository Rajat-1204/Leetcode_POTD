class Solution {
public:
    int MOD = 1e9+7;
    // Recursive function
    int countWays(int n, int x, int i, vector<vector<int>>& dp){
        //  Base case - 1: if n == 0, we have got a vald way to express
        if(n == 0){
            return 1;
        }

        // Base Case - 2: if(pow(i,x) > n) so not possible to continue
        if(pow(i,x) > n){
            return 0;
        }

        // if present in dp then return it
        if(dp[n][i] != -1){
            return dp[n][i];
        }

        // 1 - Take the current index power of x
        long long take = countWays(n-pow(i,x),x,i+1,dp);

        // 2 - Do not take the power 
        long long nottake = countWays(n,x,i+1,dp);

        // return the sum of both
        return dp[n][i] = (take + nottake)%MOD;
    }
     
    int numberOfWays(int n, int x) {
        // find the max power of x that is less than or equal to n
        int maxi = 1;
        while(pow(maxi,x) <= n){
            maxi++;
        }

        // use DP for reducing repetitions
        vector<vector<int>> dp(301,vector<int>(maxi+1,-1));

        // function to calculate no. of ways
        return countWays(n,x,1,dp);
    }
};
