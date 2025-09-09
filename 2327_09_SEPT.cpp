class Solution {
public:
    //  dp create
    int dp[1001];
    // initialize MOD
    #define mod 1000000007
    // function for memo
    int solve(int idx, int d, int f, int n){
        // base case
        if(idx + d > n){
            return 1;
        }
        //  pre computed case
        if(dp[idx] != -1){
            return dp[idx];
        }

        int ans = 1;  
        // loop chlayenge jisme hum  dekhenge ki aur kis time pe kon aaskta hh delay k baad

        for(int i = idx+d; i <= min(n,idx+f);i++){
            if(i == idx+f){
                ans -= 1;
                break;
            }
            ans = (ans%mod + solve(i,d,f,n)%mod)%mod;
        }

        // return
        return dp[idx] = ans;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        //  memset
        memset(dp,-1,sizeof(dp));

        // retrn calling fn
        return solve(1,delay,forget,n);
    }
};






// secret reveal = i_day
// secret share = i_day + delay
// secret forget = i_day + forget

// [i_day + delay, i_day + forget - 1]

// n = 6 d = 2 f = 4

// day 1: 1 person  know the secret
// day 2: 1
// day 3: 1 + 1 = 2
// day 4: (1 + 1) + 1 = 3
// day 5: person 1 forget 3-1+1 = 3
// day 6: 3 + 1 + 1 = 5
