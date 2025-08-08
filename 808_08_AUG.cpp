class Solution {
public:
    // Recursive function to calculateprobability
    double func(int A, int B, vector<vector<double>>& dp){
        // base case 1 - A & B both empty
        if(A <=0 && B <=0) return 0.5;

        // base case 2 - A finishes first
        if( A <= 0 ){
            return 1.0;
        }

        // bse case 3 - B finishes first
        if( B <= 0){
            return 0.0;
        }

        // checking in dp if already present
        if(dp[A][B] != -1.0){
            return dp[A][B];
        }

        // four possible operations perform krenge
        double prob = 0.25 * (

            func(A-4,B,dp) +         // 4 A & 0 B
            func(A-3,B-1,dp) +       // 3 A & 1 B
            func(A-2,B-2,dp) +       // 2 A & 2 B
            func(A-1,B-3,dp)         // 1 A & 3 B

        );

        // return

        dp[A][B] = prob;

        return prob;
    }

    double soupServings(int n) {
        // Base case for large value i.e. > 5000 return 1
        if(n > 5000){
            return 1.0;
        }
        
        // Intialize Variables 
        // conversion ml into units
        int unit  = (n+24)/25;

        cout<< unit<< endl;

        // create DP vector    
        vector<vector<double>> dp(unit+1,vector<double>(unit+1,-1.0));

        return func(unit,unit,dp);
    }
};
